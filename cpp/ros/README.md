# ROS入门教程

## 1. 简介
ROS系统是起源于2007年斯坦福大学人工智能实验室的项目与机器人技术公司Willow Garage的个人机器人项目（Personal Robots Program）之间的合作，2008年之后就由Willow Garage来进行推动。
[ROS](http://www.ros.org/)（机器人操作系统）的本质是一个开软的软件框架，并不是一个系统，也不是语言，它实质上统一通信接口的松耦合分布方式。最大的好处是，在这个框架下的软件可以即插即用，作为机器人研究，大家可以相互交流，可以相互的调用别人的开发结果。因为机器人有太多的研究方向，这样使得研究者可以专注于自己的方向。另外一个明显的优势是它的仿真与实体机器人的无缝转化。ROS的前身是斯坦福人工智能实验室为了支持斯坦福智能机器人而建立项目，主要可以提供一些标准操作系统服务，例如硬件抽象，底层设备控制，常用功能实现，进程间消息以及数据包管理。

像ROS这种机器人软件平台在发展历史中并不少见，之前最著名的当属微软2005推出的robotics studio，当然也有科研圈子内用的很多的player，yarp，orocos等等。机器人软件平台近些年得到快速发展的原因我认为有以下几点。一方面，机器人学本身特点就是系统庞杂，学科内部松散，整体系统的实验牵涉到的方面非常多，机器人软件更是如此，各种不同开发语言，不同体系的工具包，不同的底层硬件的驱动等等异常庞杂，给开发带来了很大的困难。
另一方面，随着机器人相关领域的快速发展，例如计算机视觉 rgbd-camera，异构计算加速，很多相关算法的成熟，使得机器人科研成果向产品转化的趋势愈加明显，科研与产品开发的交流愈加密切，一个统一的机器人软件开发/测试平台显得非常必要。在这种大环境下，ROS脱颖而出成为现在事实上的机器人研究/开发的统一平台。

ROS具有清晰的文档、好用的调试工具（Rviz、rqt_plot、ROS_Debug等）、丰富的机器人Demo、庞大的社区，这些特性大大降低了ROS的入门门槛，初学者能迅速了解ROS的使用场景与方法。目前ROS主要支持Ubuntu操作系统。

## 2. 如何学习ROS?
### Step 1 : 背景知识准备：
1. 具有一定的程序员背景知识： C++，Linux，Cmake，Python，Git等
2. 具有机器人的概念： 自主移动机器人导论 （美）西格沃特（Siegwart,R.） （这是一本闲书，能短时间补充机器人的基本概念）
	* 了解机器人的定义，各种不同形态的机器人：无人机，地面机器人，水下航行器 以及其子分类。	
	* 着重了解地面机器人中的轮式移动机器人，了解不同结构的移动机器人：差速，全向，平衡车，汽车形态的等等。
	* 了解移动机器人的历史 ， 组成和功能：云台，地盘，机械臂，升降杆等。
	*  移动机器人的各种伺服结构和驱动方法。
	*  移动机器人的各种传感器的作用，以及整个移动机器人系统是如何工作的，如何实现自主。
	
### Step 2 : ROS和机器人的浅层认知：
1. ROS本身就有丰富的系列教程，建议先把官网的各个部分看一下，[ROS官网](http://www.ros.org/)
    * [ROS Wiki](http://wiki.ros.org/) ，这可能是你后面学习逛的最多的地方，涵盖ROS入门教程，机器人有关的教程，软硬件，公开课，论文等。
    * [ROS Answers](https://answers.ros.org/questions/) ，在你遇到各种奇怪的Bug后，这是最有效的解决地方。
    * [ROSCon](http://www.ros.org/news/)，ROS国际会议，你可以通过会议资料，扩充你对机器人和ROS的了解。
    * [Browsing Packages](http://www.ros.org/browse/list.php)，里面有各个版本发型的所有package列表，可以通过这个直接进入你感兴趣的package文档。但是找到略麻烦，[APIs页面](http://wiki.ros.org/APIs)的编排还是非常具有逻辑性的，这样也可以快速定位到你需要的基础库。

2.  一些典型的机器人了解，可以看[Robots](http://robots.ros.org/)
  * [TurtleBot](http://robots.ros.org/turtlebot/)，后面仿真经常用的一款机器人。
  * [Pr2](http://robots.ros.org/PR2/)，ROS框架的原型诞生在这款机器人上，该款机器人的软硬件算是相当完善和高配的了。
  * [Fetch](http://robots.ros.org/fetch/)，低成本的相对完善的机器人，具有机械臂，常用于高阶学习的仿真系统中。
  * [HandsFree 开源项目](https://github.com/HANDS-FREE/HANDS-FREE.github.io/wiki)(国产优秀项目)

  以上机器人都有比较完善的基于ROS的学习教程，同时提供了仿真学习环境。TurtleBot适合用来入门。

### Step 3 : ROS入门：
1. 安装ROS，推荐配置 [Ubuntu14.04 + ROS Indigo](http://wiki.ros.org/indigo/Installation/Ubuntu)(2018年前)，下一个合适的配置是[Ubuntu16.04 + ROS Kinetic](http://wiki.ros.org/kinetic/Installation/Ubuntu)(2018—2020年)，浏览[安装页面](http://wiki.ros.org/ROS/Installation)了解[ROS版本历史](http://wiki.ros.org/Distributions)，可以通过[Exbot](http://blog.exbot.net/)这个国内不错的博客了解更多ROS的历史，[史话篇连载](http://blog.exbot.net/?s=%E6%9C%BA%E5%99%A8%E4%BA%BA%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F%EF%BC%88ROS%EF%BC%89%E5%8F%B2%E8%AF%9D%E7%AF%87%E8%BF%9E%E8%BD%BD)

2. [Beginner Level](http://wiki.ros.org/ROS/Tutorials)，把Beginner Level的20节教程过一遍，你大概就能了解ROS的基本概念了。在这个过程中，你可以大致去了解[Tutorials 页面](http://wiki.ros.org/ROS/Tutorials)，很多和机器人有关的概念以及和ROS有关的重要库都在这个页面有涉及，比如[Stage](http://wiki.ros.org/stage/Tutorials)2D 仿真环境，[rviz](http://wiki.ros.org/visualization/Tutorials) 可视化工具，[URDF ](http://wiki.ros.org/urdf/Tutorials) 机器人结构描述语言 等。

3.  看完[Beginner Level](http://wiki.ros.org/ROS/Tutorials)后，推荐学习ros经典书籍 [ros by example](http://wiki.ros.org/Books/ROSbyExample)，ROS目前(2017.10)值得学习的书籍只有英文版本的。
  * 第一阶段学习，仿真，学习ros by example 1 indigo 前 8 章，同时可以配套国外基于Stage 2D仿真的一个 [ROS 入门ppt]( http://u.cs.biu.ac.il/~yehoshr1/89-685/)，学完这一步，你就能使用ROS实现机器人在室内的建图和自主导航了。
  * 第二阶段学习，实物挑战，购买入门级别的机器人平台实现第一阶段的自主导航实验，通过实物去理解一个实物机器人系统，领会第一阶段接触到的算法参数，的推荐实物平台，[TurtleBot](http://www.turtlebot.com/) ， [HandsFree 开源项目](https://github.com/HANDS-FREE/HANDS-FREE.github.io/wiki)(国产优秀项目)

### Step 4 : ROS进阶：

这一步比较适合愿意花三年以上的时间探索机器人的学者，如果你只是想花几个月了解机器人和ROS，进行完Step 3 就足够了。

1.  ros by example 1 indigo 后几章节 + ros by example 2，你会接触到ROS的生态系统，比如语音识别，图像识别，人机交互，行为决策，3D物理仿真，机械臂规划和抓取，云台的控制等，这就类似导论了，每一章都可以扩充为一个专业领域。
2. 学习使用 [Gazebo](http://www.gazebosim.org/) 3D仿真器，能看懂[URDF机器人描述语言](http://gazebosim.org/tutorials?tut=ros_urdf&cat=connect_ros)，后面很多实验都是要用Gazebo的，实物研究效率有点低，不过Gazebo非常耗用系统资源，为了你能愉快的科研，先配一台好一点的主机，我的机子是 i7 6700k+GTX1070。
3.  更深入的去了解机器人系统，机械结构，电路控制，传感器，通信，机械臂控制等，参考HandsFree的[分组培养要求](https://github.com/HandsFree-Nwpu/HandsFree-Nwpu.github.io/wiki/2.3-Club-Group)
4. 一些重要包的理解：
	- [Action](http://wiki.ros.org/actionlib)
	- [ROS Control](http://wiki.ros.org/ros_control)
	- [Joint State Publisher](http://wiki.ros.org/joint_state_publisher)
	- [Robot State Publisher](http://wiki.ros.org/robot_state_publisher)
	- [Joint Trajectory Controller](http://wiki.ros.org/joint_trajectory_controller)
	- [URDF](http://wiki.ros.org/urdf)
	- [Xacro](http://wiki.ros.org/xacro)
	- [Launch XML](http://wiki.ros.org/roslaunch/XML)
	- [Gazebo Connect to ROS](http://gazebosim.org/tutorials?cat=connect_ros)



## 3. 专题介绍

### ROS和机械臂

[cite handsfree 8.3 Object Pick Place](https://github.com/HANDS-FREE/HANDS-FREE.github.io/wiki/8.3-Object-Pick-Place)

如果你能按照我说的完成前几步的话，你应该已经会用MoveIt!，并能用其做简单的运动规划了。当然，如果你想成为机械臂开发大神的话，你还需要重点学习MoveIt!的代码API。MoveIt!的API不少，你需要多尝试，找到最适合你们机械臂使用的API（推荐C++的API）。

在MoveIt!中，碰撞检测使用的是FCL库。你需要了解和学习FCL的API，并将其融入到机械臂的运动规划中去。

MoveIt!默认使用OMPL库来做运动规划，你可以去OMPL的官网仔细地学习一下它的使用方法。如果你有时间的话，也可以研究一下其他几种规划器的效果如何，比如STOMP、SBPL、CHOMP等。
如果你认为你已经对MoveIt!的使用了如指掌，你可以尝试挑战一下难度——根据你们自己机械的实际情况，手写IK解算插件并将其集成到OMPL中去。

完成以上之后，你如果发现自己还想在机械臂领域有更多的提升空间，那工程开发显然已经不能满足你的需求了，你需要阅读机械臂方面的论文以及专业书籍。这里我推荐《Robotics - Modelling, Planning and Control》这本书，里面深入地讲解了机器人的建模、轨迹规划以及运动控制等相关内容。

网站<br>
[MoveIt!官方文档](http://moveit.ros.org/documentation)

西工大一小学生：<br>
[ros_control攻略](http://blog.exbot.net/archives/2337)

古月居：<br>
[ROS探索总结（二十五）——MoveIt!基础](http://www.guyuehome.com/435)<br>
[ROS探索总结（二十六）——MoveIt!编程](http://www.guyuehome.com/455)<br>
[ROS探索总结（三十一）——ros_control](http://www.guyuehome.com/890)<br>

redefine：<br>
[运动规划 (Motion Planning): MoveIt! 与 OMPL](http://www.roswiki.com/read.php?tid=402&fid=9&page=1)<br>
[基于OMPL的采样运动规划算法(Sampling-based Motion Planning)](http://www.roswiki.com/read.php?tid=535&fid=9)<br>

yaked：<br>
[在qt下编写基于KUKA youbot API的程序](http://blog.csdn.net/yaked/article/details/42265325)<br>
[用ROS控制KUKA youbot的5自由度机械臂和夹子](http://blog.csdn.net/yaked/article/details/45022047)<br>
[给KUKA youbot机械臂添加dynamic reconfig](http://blog.csdn.net/yaked/article/details/45061889)<br>
[Actionlib与KUKA youbot机械臂](http://blog.csdn.net/yaked/article/details/45098549)<br>
[利用rqt_plot与matlab分析KUKA youbot的joint_states信息](http://blog.csdn.net/yaked/article/details/45534381)<br>
[KUKA youbot机械臂与Moveit工具包（1）](http://blog.csdn.net/yaked/article/details/45618877)<br>
[KUKA youbot机械臂与Moveit工具包（2）](http://blog.csdn.net/yaked/article/details/45621517)<br>
[KUKA youbot机械臂与Moveit工具包（3）](http://blog.csdn.net/yaked/article/details/46840763)<br>
[Gazebo与ros_control（1）：让模型动起来](http://blog.csdn.net/yaked/article/details/51412781)<br>
[Gazebo与ros_control（2）：七自由度机械臂和两轮差速运动小车](http://blog.csdn.net/yaked/article/details/51417742)<br>
[Gazebo与ros_control（3）：Moveit输出规划轨迹到Gazebo](http://blog.csdn.net/yaked/article/details/51436262)<br>
[Gazebo与ros_control（4）：举一反三，实战youBot](http://blog.csdn.net/yaked/article/details/51483531)<br>

邱博士：<br>
[使用MoveIt进行运动规划](http://blog.exbot.net/archives/2908)<br>
[实例介绍机械臂运动规划及前沿研究方向](http://www.leiphone.com/news/201703/0JJyEB2eqdRe9XS8.html)<br>
[邱博士知乎问题回答](https://www.zhihu.com/people/fly_qq/answers)<br>

创客智造：<br>
[MoveIt!入门教程系列](http://www.ncnynl.com/archives/201610/947.html)<br>

## 4. 其它资源
书籍:

《Effective_Robotics_Programming_with_ROS_Third_Edition》<br>
《Learning_ROS_for_Robotics_Programming_Second_Edition》<br>
《Mastering_ROS_for_Robotics_Programming》<br>
《Programming_Robots_with_ROS》<br>
《Robot_Operating_System(ROS)_The_Complete_Reference》<br>
《ROS_By_Example_2_Indigo》<br>
《ROS_Robotics_By_Example》<br>

网站：

[Exbot](http://blog.exbot.net/)<br>
[HandsFree](https://github.com/HANDS-FREE/HANDS-FREE.github.io/wiki)<br>
[官方教程的中文翻译](http://wiki.ros.org/cn/ROS/Tutorials/)<br>
[创客智造](http://www.ncnynl.com/)<br>

网页：

[ROS机器人操作系统相关书籍、资料和学习路径](http://blog.csdn.net/zhangrelay/article/details/78179097)

## 5. 课程作业

作业1：
在Ubuntu下安裝配置ROS，学完[Beginner Level](http://wiki.ros.org/ROS/Tutorials)的20节教程。

作业2：
在Stage 2D仿真环境下，实现机器人的建图和自主导航。






