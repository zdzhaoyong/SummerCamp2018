# 智能系统实验室-2018新人暑期培训计划

## 1. 课程目标
随着团队扩大和节奏加快，目前依靠大家自学的方式学习速度已经远远满足不了需求，根据之前的共识和这段时间的思考，我们整理了本方案，计划在明年研究生入学前开展学前强化学习班，旨在快速引导新生入门相关领域，同时也给其后续学习提供系统性的资料。
而在这之前，我们需要号召高年级学生系统性地整理相关资料，通过协作方式完善后试讲，确认OK后整理到一个统一的文件体系中。

协作gitlab：http://192.168.1.3/zhaoyong/SummerCamp2018

课程针对学员，有针对性地提升以下能力：

- 基础能力：所有人了解基础的编程知识，注意事项，了解常用工具的使用方法;
- SLAM    ：学习SLAM的基础知识，并带领学员一步一步自己实现一个简单的ORBSLAM;
- AI      ：学习AI相关的基本知识，并通过一些实例让大家自己实现常见的功能;

## 2. 课程列表
所有的课程被归类成以下几个Topic：

- tool      ： 包含常用的环境，工具
- cpp       ： 包含C++程序入门的一些课程
- python    :  包括python基本使用教程
- slam      ： SLAM入门课程
- ai        ： AI入门课程

每个Topic都被分成约3个学时Lessons，每个Lesson可以是Lecture，Tutorial或Lab：

- Lecture ： 演讲课，主讲者进行演讲而学员以听为主，课程应尽量生动易懂，同时建议学员根据自身情况预习并在Lecture课程中做好记录;
- Tutorial： 讨论课，课程建议包含约一小时的内容讲述和两小时的学员实践练习讨论，建议学员根据自身情况预习;
- Lab     :  实验课，包含少量内容介绍，主体为操作学习的课程;

Lesson中途可以适当休息，或者安排其他活动。以下是全部Lessons的列表和简要说明：

|课程文件夹|课程描述|课程类型|主讲人|
| ------------- |:-------------|:--------:|:--------:|
|tool/linux     |Linux入门，常用工具介绍，Bash命令ShellToolkit，cd,ls,echo,apt,ssh,dpkg,locate等，Bash编程实践|Tutorial||
|[tool/git][git]       |git工具介绍和协作开发实践|Lab|张咪|
|[tool/markdown][markdown]  |markdown语言介绍和使用实验课程|Lab|马文科|
|[tool/notebook][notebook]  |ipython notebook介绍和使用实验课程|Lab|冷鹏宇|
|tool/cmake     |介绍编译原理，引入CMake，并练习使用cmake进行编译，介绍PICMake，练习使用PICMake进行编译，Linux下编写简单包含三方库本地库的工程，并分别用Makefile，qmake，CMake编译|Lab|[王伟]|
|tool/latex     |latex语言介绍和学习实践|Lab|张咪|
|tool/docmanage |mendeley等文档管理软件|Lab|张咪|
|tool/docker    |docker入门介绍|Lab|赵勇|
|cpp/helloc     |C语言入门回顾，这里主要介绍与C语言重叠的部分，包含宏定义，变量，函数，循环体，指针，函数指针，数组，结构体，联合体等部分，编写简单函数库，并使用Makefile进行编译|Tutorial|杨君|
|cpp/hellocpp   |C++语言入门回顾，介绍引用，重载，类成员函数，继承多态，编写简单函数库，并使用Makefile进行编译，引入qmake，Debug|Tutorial|贺宇|
|cpp/stl        |STL介绍，引入模板类，介绍vector,list,map,set等，练习编写自己的list实现|Tutorial|程诚|
|cpp/cpp11      |C++11标准介绍，引入多线程，智能指针，原子锁，信号量等概念，练习多线程中使用智能指针，原子锁，信号量等|Tutorial|
|cpp/style      |介绍GoogleCppStyle，强调编程风格，练习自己实现一个智能指针模板类，大家讨论各自的代码中存在什么问题|Tutorial|马文科|
|cpp/qt         |介绍基本的Qt界面编程，并带着学员实现一个简单的界面程序|Tutorial|王伟|
|cpp/ros        |介绍ROS机器人操作系统，并带着学员实现一个简单的ROS通信程序，课程要求学员预习并提前安装ROS库|Tutorial|马文科|
|cpp/opengl     |课程介绍基本的OpenGL操作，并实践显示简单的模型元素|Tutorial|
|cpp/effectivecpp|介绍EffectiveC++中的部分内容，并带着学员反思之前程序中存在的问题|Tutorial|
|python/hellopython|编程语言特性，程序结构，基础技术框架，编程风格，对象特性，核心数据类型，字符串，列表，元祖，字典，表达式与运算符|Tutorial|李清|
|python/more    |if,while,for,迭代器，生成器，文件对象，os模块，os模块常用接口，函数，类,继承，重载|Tutorial|李清|
|python/module  |模块基础，模块机制，异常处理，常用科学计算模块|Tutorial|王磊|
|slam/summary   |初识SLAM，什么是SLAM，SLAM研究包含什么内容，如何开展SLAM研究，SLAM的未来|Lecture|张咪|
|slam/cv        |图像处理相关,opencv入门介绍|Tutorial|王伟|
|slam/geo2d3d   |二维，三维中的点，线，面和线性变换,思考题讨论|Tutorial|
|slam/opt_linear|线性优化入门及实例，利用SVD分解和Eigen库求解最小二乘问题实验，并引入Ransac提升拟合效果|Tutorial|程诚|
|slam/match     |图像匹配，光流，特征点匹配，并求解二维对应warp|Tutorial|程诚|
|slam/camera    |介绍各种传感器，相机模型，畸变模型和标定工具|Tutorial|杨君|
|slam/liegroup  |三维中的李群和李代数，此章理论有深度，建议预习|Lecture|范帝凯|
|slam/opt_nolinear|非线性优化入门及实例，Ceres实例求解标定参数|Tutorial|
|slam/orbslam   |ORBSLAM代码结构解析|Lecture|
|slam/gorbslam  |ORBSLAM的GSLAM实现，将在后续的课程中带着大家逐步完善它|Tutorial|
|slam/initialize|两帧重建介绍及实验,完成GSLAM-ORBSLAM中的初始化并显示|Tutorial|
|slam/pnp       |PnP方法介绍和代码实现|Tutorial|程诚|
|slam/triangulate|地图生成和三角化|Tutorial|
|slam/dataassociation|地图数据关联|Tutorial|
|slam/ba        |BundleAdjust方法介绍和代码实现|Tutorial|程诚|
|slam/loopdetect|回环检测介绍和代码实现|Tutorial|
|slam/icp       |ICP方法和代码实现|Tutorial|王伟|
|slam/posegraph |位姿图优化|Tutorial|
|slam/direct    |直接法|Lecture|
|slam/vins      |VINS代码解析|Lecture|
|slam/mapfusion |讲解MapFusion框架，并实践编写一个最简单的Map2DFusion插件|Tutorial|王伟|
|slam/dense     |讲解稠密重建的方法，并时间编写一个最简单的稠密重建程序|Tutorial|杨君|
|slam/mesher    |讲解如何构建三角网格模型并进行纹理贴图|Tutorial|张咪|
|ai/summary     |初识人工智能，什么是人工智能，如何开展人工智能研究，人工智能的未来|Tutorial|童品模|
|ai/mlbasic     |机器学习基础，机器学习涉及的基本点|Tutorial|王磊|
|ai/probability |机器学习中涉及的统计概率以及信息论相关知识点|Tutorial|韩鹏程|
|ai/nn          |神经网络基本介绍|Tutorial|童品模|
|ai/bp          |神经网络反向传播算法,简要包括随机梯度下降法等优化方法|Tutorial|李清|
|ai/tricks      |关于神经网络的一些技巧包括激活函数、dropput、正则化、loss函数定义选择|Tutorial|冷鹏宇|
|ai/optimizer   |深度模型中的优化介绍|Tutorial|冷鹏宇|
|ai/caffe       |使用教程，简单源码分析，部分API接口讲解，python接口说明|Tutorial|韩鹏程|
|ai/tensorflow  |使用教程，简单源码分析，部分API接口讲解|Tutorial|王磊|
|ai/cnn         |CNN介绍和实验|Tutorial|冷鹏宇|
|ai/lstmRNN     |lstm以及rnn序列神经网络介绍|Tutorial|王磊|
|ai/svmPCA      |SVM介绍和实验，线性因子模型介绍|Tutorial|李清|
|ai/dlcore      |自编码器，表示学习，结构化概率模型，蒙特卡罗方法，配分函数，近似推断|Tutorial|韩鹏程|
|ai/rbmDBN      |无监督深度学习技术DBN原理介绍，生成模型介绍|Tutorial|王磊|
|ai/GANs        |GANs基本原理和应用介绍|Tutorial|韩鹏程|
|ai/ReforceLearning|强化学习基本原理介绍|Tutorial|李清|
|ai/yoloFastRCNN|yolo原理与实验,FastRcnn经典框架及技术要点介绍|Tutorial|冷鹏宇|
|ai/largeScaleLearning|大规模深度学习涉及的技术点，GPU,分布式，模型压缩,动态结构，FPGA硬件|Tutorial|韩鹏程|

[caffe]: ai/caffe/README.md
[gans]: ai/gans/README.md
[notebook]: tool/notebook/README.md
[cnn]: ai/cnn/README.md
[yoloFastRCNN]: ai/yoloFastRCNN/README.md
[aitricks]: ai/aitricks/README.md
[aiOptimizer]: ai/Optimizer/README.md
[markdown]: tool/markdown/README.md
[ros]: cpp/ros/README.md
[hellopython]: python/hellopython/README.md
[pythonmore]: python/more/README.md
[bp]: ai/bp/README.md
[liegroup]: slam/liegroup/README.md
[match]: slam/match/README.md
[stl]: cpp/stl/README.md
[git]: tool/git/README.md
[docker]: tool/docker/README.md

## 3. 学习课表（2018-07-08月）
学习课表是根据情况从课程列表选择一部分课程进行讲述，对于未开课课程请学员根据自身情况自学。以下课程中的基础类为必修，对于SLAM方向学员来说AI为选修，对于AI方向学员来说SLAM为选修。

|日期|上午(09：00 - 12：00)|下午( 14：30 - 17：30)|晚上(19：00 - 22：00)|
|---|:---:|:---:|:---:|
|1  |tool/linux       |tool/git           ||
|2  |tool/markdown    |cpp/helloc         |tool/notebook|
|3  |slam/summary     |cpp/hellocpp       |tool/cmake|
|4  |ai/summary       |cpp/stl            |python/hellopython|
|5  |slam/geo2d3d     |cpp/cpp11          |python/more|
|6  |ai/mlbasic       |cpp/style          |python/module|
|7  |slam/opt_linear  |ai/probability     |
|8  |slam/match       |ai/nn              |
|9  |slam/camera      |ai/bp              |
|10 |slam/liegroup    |ai/tricks          |
|11 |slam/opt_nolinear|ai/optimizer       |
|12 |slam/orbslam     |ai/caffe           |
|13 |slam/gorbslam    |ai/tensorflow      |
|14 |slam/initialize  |ai/cnn             |
|15 |slam/pnp         |ai/lstmRNN         |
|16 |slam/triangulate |ai/svmPCA          |
|17 |slam/ba          |ai/dlcore          |
|18 |slam/loopdetect  |ai/rbmDBN          |
|19 |slam/icp         |ai/GANs            |
|20 |slam/posegraph   |ai/ReforceLearning |
|21 |slam/direct      |ai/yoloFastRCNN    |
|22 |slam/vio         |ai/largeScaleLearning
|23 |slam/vins        |cpp/effectivecpp   |
|24 |tool/latex       |tool/mendeley|

## 4. 课程准备说明

每个课程都包含:

- doc
- README.md (包含课程介绍,[说明],[大作业])

注意事项：

- 请控制每个Lesson上课时间不多于3小时
 

## 5. TODO
### 5.1. 文档整理方式&规则

- 如何更容易上手?


### 5.2. 上课模式?
按课表进行上课or(每天固定时间答疑)or每周固定时间答疑

### 5.3. README模板
```
# 课程名称
## 1. 本课程介绍
README是用来给读者准备的课程说明

## 2. 如何学本课程?
可以参考示例/cpp/stl课程的写法.
每个README都应包含且仅包含四个标题.

## 3. 课程目录

## 4. 课程作业
无
```

