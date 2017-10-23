# 非线性优化(Nolinear Optimization)

标签（空格分隔）： SLAM Optimize

---

## 1. 概述
在SLAM系统中，优化问题占据着举足轻重的地位，在前端和后端的核心中都反复出现，如相机的标定，位姿的求解, BundleAdjust, Pose Graph 优化等，可以说是SLAM的一大核心．学好本课程可以帮助你建立非线性优化中用到的基本概念和流程，从而能够更好地理解SLAM中各优化环节的工作原理．

## 2. 如何学习本课程？

参考资料：
最优化理论
凸优化

## 3. 课程内容

### 3.1. 问题引出
现有已知其表达式函数：$$y=f(x,p)$$
给定n组x和ｙ，求解参数p.

为求误差的最小平方和，根据函数表达式的类型可分为两种：线性和非线性。
如果函数是线性的，则表达式可转化为$Ax=y$,其解即$x=(A^TA)^{-1}A^Ty$,通常通过矩阵分解求解.

如果函数是非线性的，常常可把问题转化为：
$$\hat{p}=argmin \sum(y_i-f(x_i,p))^2$$
为求误差的最小平方和，非线性最小二乘没有closed-form，通常用迭代法求解。

迭代法，即在每一步update未知量逐渐逼近解，可以用于各种各样的问题（包括最小二乘），比如求的不是误差的最小平方和而是最小立方和。梯度下降是迭代法的一种，可以用于求解最小二乘问题（线性和非线性都可以）。高斯-牛顿法是另一种经常用于求解非线性最小二乘的迭代法（一定程度上可视为标准非线性最小二乘求解方法）。还有一种叫做Levenberg-Marquardt的迭代法用于求解非线性最小二乘问题，就结合了梯度下降和高斯-牛顿法。所以如果把最小二乘看做是优化问题的话，那么梯度下降是求解方法的一种，是求解线性最小二乘的一种，高斯-牛顿法和Levenberg-Marquardt则能用于求解非线性最小二乘。具体可参考维基百科（Least squares, Gradient descent, Gauss-Newton algorithm, Levenberg-Marquardt algorithm）
下面我们详细介绍梯度下降法，高斯-牛顿法和Levenberg-Marquardt．

### 3.2. Levenberg–Marquardt迭代法
对于3.1中的问题，可将x看作已知量，要求的参数p作为自变量，将f(p)对p的一阶导数称为Jacobian矩阵$J=\frac{\partial f(p)}{\partial p}$，并将f(p)对p的二阶导数称为Hessian矩阵．

将函数进行二阶泰勒展开可表示为：
$$f(p+h)=f(p)+h^TJ+h^THh/2+O(||h||^3)$$

已知$y=f(x,p)$,并给定一组观测x,y，估计参数p,LM算法的步骤如下：
1. 取初始点$p_0$，参数列表：终止控制常数$\epsilon$,计算$e=||y-f(x,p_0)||$,$\lambda=10^{-3}$,v=10;
2. 计算Jacobian矩阵J,根据方程$(J^TJ+\lambda I)\delta=J^Te$求解参数更新量$\delta$;
3. 根据参数更新量估计更新后的p',根据更新的p'计算$e'=||y-f(x,p')||$，若$e'<e$,则认为迭代成功，接受更新$p=p',\lambda=\lambda/v$，检查$e'>\epsilon$确定是否继续迭代;否则令$\lambda=\lambda*v$继续迭代。

![](http://s7.sinaimg.cn/middle/6d8f1b93gabf8d6b76116&690)


### 3.3. 示例：使用Levenberg–Marquardt迭代法求解PnP问题

下面的C++代码展示了如何使用LM算法求解PnP问题，其中Jacobian的求解可利用[链式法则](chainrule.md),其中关于如何在李群的流型上求导祥见[slam/lie_group](../../slam/lie_group/README.md)课程.
```
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

```

### 3.4. 稀疏非线性优化？图优化
上节中的PnP求解只需要优化6个参数，其中的Hessian矩阵都包含有效的值，但在SLAM的后端优化中参数与参数之间并不是一直耦合的，我们只需要关心相互有联系的参数并对其进行优化，这个时候往往Hessian矩阵是高度稀疏的，如图

### 3.5. 示例：使用稀疏非线性优化求解Bundle问题

### 3.5. 常用非线性求解库的使用

[g2o](g2o.md)
[ceres](ceres.md)
[gtsam](gtsam.md)

## 4. 课程作业
由于效率高，精度较好的特点，Pose Graph在SLAM中被广泛应用，请参考GSLAM中的Optimizer，编写程序，实现Pose Graph的优化求解（尽可能使用手动求导）。







