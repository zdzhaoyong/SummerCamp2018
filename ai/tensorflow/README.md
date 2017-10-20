# tensorflow

标签（空格分隔）： SummerCamp2018 tensorflow

---

[toc]

## 1. 概述

###  1.1. 什么是tensorflow?

TensorFlow 是一个编程系统, 使用图来表示计算任务. 图中的节点被称之为 op (operation 的缩写). 一个 op 获得 0 个或多个 Tensor, 执行计算, 产生 0 个或多个 Tensor. 每个 Tensor 是一个类型化的多维数组. 例如, 你可以将一小组图像集表示为一个四维浮点数数组, 这四个维度分别是 [batch, height, width, channels].

一个 TensorFlow 图描述了计算的过程. 为了进行计算, 图必须在 会话 里被启动. 会话 将图的 op 分发到诸如 CPU 或 GPU 之类的 设备 上, 同时提供执行 op 的方法. 这些方法执行后, 将产生的 tensor 返回. 在 Python 语言中, 返回的 tensor 是 numpy ndarray 对象; 在 C 和 C++ 语言中, 返回的 tensor 是 tensorflow::Tensor 实例.

## 1.2. 为什么要用tensorflow?

**八大机器学习框架的对比：**

(1)  TensorFlow：深度学习最流行的库之一，是谷歌在深刻总结了其 前身 DistBelief 的经验教训上形成的；它不仅便携、高效、可扩 展，还能再不同计算机上运行:小到智能手机，大到计算机集群都能；它是一款轻量级的软件，可以立刻生成你的训练模型，也能重新实现它；TensorFlow 拥抱创新，有强大的社区、企业支持， 因此它广泛用于从个人到企业、从初创公司到大公司等不同群体。

(2) Caffe: 卷积神经网络框架，专注于卷积神经网络和图像处理，是用 C ++语言写成的。

(3)  Chainer: 一个强大、灵活、直观的机器学习 Python软件库，能够在一台机器上利用多个 GPU，是由深度学习创业公司 Preferred Networks 开发；Chainer 的设计基于define by run 原则，也就是说，该网络在运行中动态定义，而不是在启动时定义。

(4)  CNTK: 微软研究人员开发的用于深度神经网络和多GPU 加速技 术的完整开源工具包。微软称 CNTK在语音和图像识别方面，比 谷歌的 TensorFlow 等其它深度学习开源工具包更有优势。

(5) Deeplearning4j: 专注于神经网络的 Java 库，可扩展并集成 Spark，Hadoop 和其他基于 Java 的分布式集成软件。

(6) Nervana Neo: 是一个高效的 Python 机器学习库，它能够在单个机器上使用多个 GPU。

(7) Theano: 是一个用 Python 编写的极其灵活的 Python 机器学习库，用它定义复杂的模型相当容易，因此它在研究中极其流行。

(8) Torch: 是一个专注于 GPU 实现的机器学习库，得到了几个大公司的研究团队的支持。


**TensorFlow 的优势：**

（1）可用性

TensorFlow 工作流程相对容易，API 稳定，兼容性好，并且 TensorFlow 与 Numpy 完美结合，这使大多数精通 Python 数据科学家很容易上手。与其他一些库不同，TensorFlow 不需要任 何编译时间，这允许你可以更快地迭代想法。在TensorFlow 之上已经建立了多个高级 API，例如Keras和SkFlow，这给用户使用TensorFlow 带来了极大的好处

（2）灵活性

TensorFlow 能够在各种类型的机器上运行，从超级计算机到嵌入式系统。它的分布式架构使大量数据集的模型训练不需要太多的时间。TensorFlow 可以同时在多个 CPU，GPU 或者两者混合运行。

（3）效率

自 TensorFlow 第一次发布以来，开发团队花费了大量的时间和努力 来改进TensorFlow 的大部分的实现代码。 随着越来越多的开发人 员努力，TensorFlow 的效率不断提高。

（4）支持

TensorFlow 由谷歌提供支持，谷歌投入了大量精力开发 TensorFlow，它希望 TensorFlow 成为机器学习研究人员和开发人员的通用语言。此外，谷歌在自己的日常工作中也使用 TensorFlow，并且持续对其提供支持，在 TensorFlow 周围形成了 一个强大的社区。谷歌已经在 TensorFlow 上发布了多个预先训练好的机器学习模型，他们可以自由使用。

---

## 2. 学习目标与学习方法
### 2.1. 目标
　　掌握tensorflow的基本用法，

### 2.2. 方法
　　推荐读者根据本教程内容的步骤进行操作，同时浏览推荐的学习资料，如有任何不清楚的地方可参考推荐的学习资料或者自行搜索答案和找他人解答。
　　
### 2.3. 推荐学习资料

[[TensorFlow 官方文档 从首个版本就非常详细。](http://wiki.jikexueyuan.com/project/tensorflow-zh/)

[LearningTensorFlow: A beginners guide to a powerful framework.，包含详细的接口定义，各种学习资源和例子。](http://learningtensorflow.com/index.html)

[TensorFlow学习笔记1：入门 系列学习笔记，中文版](http://www.jeyzhang.com/tensorflow-learning-notes.html)


---

## 3. 课程内容
* [下载及安装](content/下载与安装.md)
* [基本用法](content/基本用法.md)
* [minst机器学习入门](content/MNIST机器学习入门/MNIST机器学习入门.md)
* [深入MNIST](content/深入MNIST.md)
* [TensorFlow运作方式入门](content/TensorFlow运作方式入门/TensorFlow运作方式入门.md)




---

## 4.　课程作业


