#include <eigen3/Eigen/Cholesky>
#include <GSLAM/core/GSLAM.h>
#include <GSLAM/core/Random.h>
#include <GSLAM/core/Timer.h>

#define RESIDUAL_SIZE 2
#define PARA_SIZE 6

typedef Eigen::Matrix<double,RESIDUAL_SIZE,PARA_SIZE> PnPJacobian;
typedef Eigen::Matrix<double,PARA_SIZE,PARA_SIZE>     PnPHessian;
typedef Eigen::Matrix<double,PARA_SIZE,1>             JacobianError;
typedef Eigen::Matrix<double,2,3>                     Matrix23;

typedef Eigen::Matrix<double,6,1>                     Vector6d;

using   Eigen::Vector2d;
using   GSLAM::SE3;
using   GSLAM::Point3d;
using   GSLAM::Point2d;

inline double HuberWeight(double dErrorSquared, double dSigmaSquared)
{
  if(dErrorSquared < dSigmaSquared)
    return 1;
  else
    return sqrt(dSigmaSquared / dErrorSquared);
}

double cacuSumError(  SE3& world2camera,
                const std::vector<Point3d>& objectPoints,
                const std::vector<Point2d>& imagePoints,
                const GSLAM::Camera&        camera,
                const double&               dSigmaSquared)
{
    double result=0;
    for(size_t i=0;i<objectPoints.size();i++)
    {
        Point3d pcam = world2camera*objectPoints[i];
        Point2d err  = camera.Project(pcam)-imagePoints[i];
        double  info = HuberWeight(err.x*err.x+err.y*err.y,dSigmaSquared);
        err = err*info;
        result+=err.x*err.x+err.y*err.y;
    }
    return result;
}

bool solvePnP(  SE3& world2camera,
                const std::vector<Point3d>& objectPoints,
                const std::vector<Point2d>& imagePoints,
                const GSLAM::Camera&        camera)
{
    assert(camera.isValid());
    assert(objectPoints.size()==imagePoints.size());

    int    maxItNum=50;
    double lambda=0.01;
    double dSigmaSquared=0.01;
    double lambdaFactor=10;

    GSLAM::SE3 w2c=world2camera;
    double curError=cacuSumError(w2c,objectPoints,imagePoints,camera,dSigmaSquared);

    for(int it=0;it<maxItNum;it++)
    {
        PnPHessian Hessian=PnPHessian::Identity()*lambda;
        JacobianError jacerr=JacobianError::Zero();
        for(size_t i=0;i<objectPoints.size();i++)
        {
            // estimate error and weight
            Point3d pcam = w2c*objectPoints[i];
            Point2d err  = imagePoints[i]-camera.Project(pcam);// WARNNING: The error should be y-f(x) and not f(x)-y
            double  info = HuberWeight(err.x*err.x+err.y*err.y,dSigmaSquared);
            err = err*info;

            // estimate jacobians, see slam/lie_group about how to compute the Jacobian on manifold
            Eigen::Vector3d pc(pcam.x,pcam.y,pcam.z);
            PnPJacobian     jac;
            double invZ =1./pc(2);
            double invZ2=invZ*invZ;
            const double& x=pc(0),&y=pc(1);
            jac<<invZ , 0    , -x*invZ2 , -x*y*invZ2      , (1+(x*x*invZ2))  , -y*invZ ,
                 0    , invZ , -y*invZ2 , -(1+y*y*invZ2)  , x*y*invZ2        , x*invZ ;

            // estimate Hessian and JacobianError
            Hessian += jac.transpose()*info*jac;
            jacerr  += jac.transpose()*Vector2d(err.x,err.y);
        }

        // caculate update, solve Hessian*inc=jacerr
        Vector6d inc=Hessian.ldlt().solve(jacerr);// use Cholesky ldlt, also can use llt or QR decompose

        SE3 w2c_new=SE3::exp(*(pi::Array_<double,6>*)&inc)*w2c;
        double errorNew=cacuSumError(w2c_new,objectPoints,imagePoints,camera,dSigmaSquared);

        double facError=errorNew/curError;
        if(facError>=1)
        {
            lambda*=lambdaFactor;
        }
        else
        {
            w2c=w2c_new;
            curError=errorNew;
            lambda/=lambdaFactor;

//            printf("iter:%d,curError:%lf,facError:%lf\n",it,curError,facError);
//            std::cout<<"inc:"<<inc.transpose()<<std::endl;

            if(facError>0.9999) break;// abord when small update
            if(curError<1e-7)   break;// abord when small residual
        }

    }

    world2camera=w2c;
    return true;
}


int main(int argc,char** argv)
{
    svar.ParseMain(argc,argv);
    // Prepare simulation data
    int N=svar.GetInt("SimulateNumber",2000);//number of matches
    GSLAM::SE3                                        groundPose,estPose;
    std::vector<Point3d> objectPoints;
    std::vector<Point2d> imagePoints;

    GSLAM::Camera cam({1,1});

    pi::Array_<double,6> array;
    for(int i=0;i<array.size();i++)
        array.data[i]=GSLAM::Random::RandomValue<double>();
    groundPose=GSLAM::SE3::exp(array);
    estPose=groundPose*GSLAM::SE3(pi::SO3d::exp(Point3d(0.1,0.1,0.1)),pi::Point3d(1,2,3));
    for(int i=0;i<N;i++)
    {
        pi::Point3d pCamera(GSLAM::Random::RandomValue(-1.,1.),GSLAM::Random::RandomValue(-1.,1.),1);
        pi::Point3d pWorld(groundPose*(pCamera*GSLAM::Random::RandomGaussianValue(10.,1.)));

        // add noise
        if(true)
        {
            pi::Point3d projectNoise(GSLAM::Random::RandomGaussianValue(0.,i<(0.5*N)?0.1:0.01),
                                     GSLAM::Random::RandomGaussianValue(0.,i<(0.5*N)?0.1:0.01),0);
            pCamera=pCamera+projectNoise;
        }
        objectPoints.push_back(pWorld);
        imagePoints.push_back(cam.Project(pCamera));
    }

    GSLAM::SE3 w2c=estPose.inverse();
    timer.enter("solvePnP");
    solvePnP(w2c,objectPoints,imagePoints,cam);
    timer.leave("solvePnP");
    estPose=w2c.inverse();
    LOG_IF(INFO,true)<<"GroundPose:"<<groundPose<<",EstPose:"<<estPose<<std::endl;

    return 0;
}

