# Caffe
本文档旨在让大家对caffe的基本框架有基本的了解和认知，部分内容从网站博客汇集得到。后期详细的教程请参照caffe官方网站进行学习。在阅读理解caffe代码前对CNN要有基本的了解，此外请将caffe配置好，建议把GPU版本也配置好。阅读本文档的同时打开caffe源代码进行同步阅读理解。

---

# caffe 配置
参考附件“Caffe环境安装教程 (Ubuntu 15.04，CUDA7.0，cuDNN v2, OpenCV3)”
根据自己的情况选择合适的版本进行配置。

---

# Caffe 基本认识
Caffe的全称应该是Convolutional Architecture for Fast Feature Embedding，它是一个清晰、高效的深度学习框架，它是开源的，核心语言是C++，它支持命令行、Python和Matlab接口，它既可以在CPU上运行也可以在GPU上运行，它的license是BSD 2-Clause。该网络框架主要是有监督的深度卷积神经网络，如果想研究无监督深度学习例如(RBM,CRBM,DBN)等请参照 Deep Learning Library (DLL) 库进行学习。

Caffe的设计：基本上，Caffe 遵循了神经网络的一个简单假设----所有的计算都是以layer的形式表示的，layer做的事情就是take一些数据，然后输出一些计算以后的结果，比如说卷积，就是输入一个图像，然后和这一层的参数（filter）做卷积，然后输出卷积的结果。每一个layer需要做两个计算：forward是从输入计算输出，然后backward是从上面给的gradient来计算相对于输入的gradient，只要这两个函数实现了以后，我们就可以把很多层连接成一个网络，这个网络做的事情就是输入我们的数据（图像或者语音或者whatever），然后来计算我们需要的输出（比如说识别的label），在training的时候，我们可以根据已有的label来计算loss和gradient，然后用gradient来update网络的参数，这个就是Caffe的一个基本流程。

基本上，最简单地用Caffe上手的方法就是先把数据写成Caffe的格式，然后设计一个网络，然后用Caffe提供的solver来做优化看效果如何，如果你的数据是图像的话，可以从现有的网络，比如说alexnet或者googlenet开始，然后做fine tuning，如果你的数据稍有不同，比如说是直接的float vector，你可能需要做一些一般性的配置，阅读Caffe的一些例子比如logistic regression的例子可能会很有帮助。

Fine tune方法：fine tuning的想法就是说，在imagenet那么大的数据集上训练好一个很好的网络了，那别的任务上肯定也不错，所以我们可以把pretrain的网络拿过来，然后只重新train最后几层，重新train的意思是说，比如我以前需要classify imagenet的一千类，现在我只想识别是狗还是猫，或者是不是车牌，于是我就可以把最后一层softmax从一个4096*1000的分类器变成一个4096*2的分类器，这个strategy在应用中非常好使，所以我们经常会先在imagenet上pretrain一个网络，因为我们知道imagenet上training的大概过程会怎么样。

Caffe可以应用在视觉、语音识别、机器人、神经科学和天文学。Caffe提供了一个完整的工具包，用来训练、测试、微调和部署模型。

## Caffe的亮点：

	(1)、模块化：Caffe从一开始就设计得尽可能模块化，允许对新数据格式、网络层和损失函数进行扩展。

	(2)、表示和实现分离：Caffe的模型(model)定义是用Protocol Buffer语言写进配置文件的。以任意有向无环图的形式，Caffe支持网络架构。Caffe会根据网络的需要来正确占用内存。通过一个函数调用，实现CPU和GPU之间的切换。

	(3)、测试覆盖：在Caffe中，每一个单一的模块都对应一个测试。

	(4)、Python和Matlab接口：同时提供Python和Matlab接口。

	(5)、预训练参考模型：针对视觉项目，Caffe提供了一些参考模型，这些模型仅应用在学术和非商业领域，它们的license不是BSD。

## Caffe架构：

	(1)、数据存储：Caffe通过”blobs”即以4维数组的方式存储和传递数据。Blobs提供了一个统一的内存接口，用于批量图像（或其它数据）的操作，参数或参数更新。Models是以Google Protocol Buffers的方式存储在磁盘上。大型数据存储在LevelDB数据库中。

	(2)、层：一个Caffe层(Layer)是一个神经网络层的本质，它采用一个或多个blobs作为输入，并产生一个或多个blobs作为输出。网络作为一个整体的操作，层有两个关键职责：前向传播，需要输入并产生输出；反向传播，取梯度作为输出，通过参数和输入计算梯度。Caffe提供了一套完整的层类型。

	(3)、网络和运行方式：Caffe保留所有的有向无环层图，确保正确的进行前向传播和反向传播。Caffe模型是终端到终端的机器学习系统。一个典型的网络开始于数据层，结束于loss层。通过一个单一的开关，使其网络运行在CPU或GPU上。在CPU或GPU上，层会产生相同的结果。

	(4)、训练一个网络：Caffe训练一个模型(Model)靠快速、标准的随机梯度下降算法。

	在Caffe中，微调(Fine tuning)，是一个标准的方法，它适应于存在的模型、新的架构或数据。对于新任务，Caffe 微调旧的模型权重并按照需要初始化新的权重。

Blobs,Layers,and Nets：深度网络的组成模式表示为数据块工作的内部连接层的集合。以它自己的model模式，Caffe定义了层层(layer-by-layer)网络。Caffe网络定义了从低端到顶层整个model，从输入数据到loss层。随着数据通过网络的前向传播和反向传播，Caffe存储、通信、信息操作作为Blobs。Blob是标准阵列和统一内存接口框架。Blob用来存储数据、参数以及loss。随之而来的layer作为model和计算的基础，它是网络的基本单元。net作为layer的连接和集合，网络的搭建。blob详细描述了layer与layer或net是怎样进行信息存储和通信的。Solver是Net的求解。

>Blob

	Blob 存储和传输：一个blob是对要处理的实际数据的封装，它通过Caffe传递。在CPU和GPU之间，blob也提供同步能力。在数学上，blob是存储连续的N维数组阵列。

	Caffe通过blobs存储和传输数据。blobs提供统一的内存接口保存数据，例如，批量图像，model参数，导数的优化。

	Blobs隐藏了计算和混合CPU/GPU的操作根据需要从主机CPU到设备GPU进行同步的开销。主机和设备的内存是按需分配。

	对于批量图像数据，blob常规容量是图像数N*通道数K*图像高H*图像宽W。在布局上，Blob存储以行为主，因此最后/最右边的维度改变最快。例如，在一个4D blob中，索引(n, k, h, w)的值物理位置索引是((n * K + k) * H + h) * W + w。对于非图像应用，用blobs也是有效的，如用2D blobs。

	参数blob尺寸根据当前层的类型和配置而变化。

	一个blob存储两块内存，data和diff，前者是前向传播的正常数据，后者是通过网络计算的梯度。

	一个blob使用SyncedMem类同步CPU和GPU之间的值，为了隐藏同步的详细信息和尽量最小的数据传输。

> Layer

	Layer计算和连接：Layer是模型(model)的本质和计算的基本单元。Layer卷积滤波、pool、取内积、应用非线性、sigmoid和其它元素转换、归一化、载入数据，计算losses.

	每一个layer类型定义了三个至关重要的计算：设置、前向和反向。（1）、设置：初始化这个layer及在model初始化时连接一次；（2）、前向：从底部对于给定的输入数据计算输出并传送到顶端；（3）、反向：对于给定的梯度，顶端输出计算这个梯度到输入并传送到低端。

	有两个前向(forward)和反向(backward)函数执行，一个用于CPU，一个用于GPU。

	Caffe layer的定义由两部分组成，层属性和层参数。

	每个layer有输入一些’bottom’blobs，输出一些’top’ blobs.

> Net 

	Net定义和操作：net由组成和分化共同定义了一个函数和它的梯度。每一层输出计算函数来完成给定的任务，每一层反向从学习任务中通过loss计算梯度.Caffe model是终端到终端的机器学习引擎。

	Net是layers组成的有向无环图(DAG)。一个典型的net开始于数据层，此layer从磁盘加载数据，终止于loss层，此layer计算目标任务，如分类和重建。

> Model 

    Model初始化通过Net::Init()进行处理。初始化主要做了两件事：通过创建blobs和layers来构建整个DAG，调用layers的SetUp()函数。它也做了一系列的其它bookkeeping（簿记）的事情，比如验证整个网络架构的正确性。

	Model格式：The models are defined in plaintext protocol buffer schema(prototxt) while the learned models are serialized as binary protocol buffer(binaryproto) .caffemodel files. The model format is defined by the protobufschema in caffe.proto.

	Forward and Backward：Forward inference, Backward learning.

> Solver & Loss

	Solver优化一个model通过首先调用forward得到输出和loss，然后调用backward生成model的梯度，接着合并梯度到权值(weight)更新尽量减少loss.Solver, Net和Layer之间的分工，使Caffe保持模块化和开放式发展。

	Loss:在Caffe中，作为大多数机器学习，学习(learning)是通过loss函数(error, cost, or objective函数)来驱动。一个loss函数指定了学习的目标通过映射参数设置（例如，当前的网络权值）到一个标量值。因此，学习的目标是找到最小化loss函数权值的设置。

	在Caffe中，loss是由网络的forward计算。每一个layer采用一组输入blobs(bottom,表示输入)，并产生一组输出blobs(top，表示输出)。一些layer的输出可能会用在loss函数中。对于分类任务，一个典型的loss函数选择是SoftmaxWithLoss函数。

	Loss weights：net通过许多个layers产生一个loss,loss weights能被用于指定它们的相对重要性。

	按照惯例，带有”loss”后缀的Caffe layer类型应用于loss函数，但其它layers是被假定为纯碎用于中间计算。然而，任一个layer都能被用于loss，通过添加一个”loss_weight”字段到一个layer定义。

	在Caffe中，最后的loss是被计算通过所有的weighted loss加和通过网络。

	Solver：Solver通过协调网络的前向推理和后向梯度形成参数更新试图改善loss达到model优化。Learning的职责是被划分为Solver监督优化和产生参数更新，Net产生loss和梯度。

	Caffe solver方法：随机梯度下降(Stochastic Gradient Descent, type:”SGD”)；AdaDelta(type:”AdaDelta”)；自适应梯度(Adaptive Gradient,type:”AdaGrad”)；Adam(type:”Adam”)；Nesterov’s Accelerated Gradient(type:”Nesterov”)；RMSprop(type:”RMSProp”).

	Solver作用：Solver是Net的求解.(1)、优化bookkeeping、创建learning训练网络、对网络进行评估；(2)、调用forward/backward迭代优化和更新参数；(3)、定期评估测试网络；(4)、整个优化快照model和solver状态。

	Solver的每一次迭代执行：(1)、调用网络forward计算输出和loss；(2)、调用网络backward计算梯度；(3)、按照solver方法，采用渐变进行参数更新；(4)、按照学习率、历史和方法更新solver状态。通过以上执行来获得所有的weights从初始化到learned model.

	像Caffe models，Caffe solvers也可以在CPU或GPU模式下运行。solver方法处理最小化loss的总体优化问题。实际的weight更新是由solver产生，然后应用到net参数。

	Layer Catalogue：为了创建一个Caffe model，你需要定义model架构在一个prototxt文件(protocol buffer definition file)中。Caffe layers和它们的参数是被定义在protocol buffer definitions文件中，对于Caffe工程是caffe.proto.

## 常用Layer介绍
Vision Layers：Vision layers通常以图像作为输入，并产生其它图像作为输出:

	(1)、Convolution(Convolution)：卷积层通过将输入图像与一系列可学习的滤波进行卷积，在输出图像中，每一个产生一个特征图；(2)、Pooling(Pooling)；(3)、Local Response Normalization(LRN)；(4)、im2col。

Loss Layers：Loss驱动学习通过比较一个输出对应一个目标和分配成本到最小化。Loss本身是被计算通过前向传输，梯度到loss是被计算通过后向传输:

	(1)、Softmax(SoftmaxWithLoss)；(2)、Sum-of-Squares/Euclidean(EuclideanLoss)；(3)、Hinge/Margin(HingeLoss)；(4)、SigmoidCross-Entropy(SigmoidCrossEntropyLoss)；(5)、Infogain(InfogainLoss)；(6)、Accuracy andTop-k。

Activation/NeuronLayers：一般Activation/Neuron Layers是逐元素操作，输入一个bottom blob，产生一个同样大小的top blob：

	(1)、ReLU/Rectified-Linearand Leaky-ReLU(ReLU)；(2)、Sigmoid(Sigmoid)；(3)、TanH/Hyperbolic Tangent(TanH)；(4)、Absolute Value(AbsVal)；(5)、Power(Power)；(6)、BNLL(BNLL)。

Data Layers：数据输入Caffe通过Data Layers，它们在网络的低端。数据可以来自于：高效的数据库(LevelDB或LMDB)、直接来自内存、在不注重效率的情况下，也可以来自文件，磁盘上HDF5数据格式或普通的图像格式：

	(1)、Database(Data)；(2)、In-Memory(MemoryData)；(3)、HDF5Input(HDF5Data)；(4)、HDF5 Output(HDF5Output)；(5)、Images(ImageData)；(6)、Windows(WindowData)；(7)、Dummy(DummyData).

Common Layers：包含一些常用数据操作：

    (1)、InnerProduct(InnerProduct)；(2)、Splitting(Split)；(3)、Flattening(Flatten)；(4)、Reshape(Reshape)；(5)、Concatenation(Concat)；(6)、Slicing(Slice)；(7)、Elementwise Operations(Eltwise)；(8)、Argmax(ArgMax)；(9)、Softmax(Softmax)；(10)、Mean-VarianceNormalization(MVN)。

Data：在Caffe中，数据存储在Blobs中：
    
    Data Layers加载输入和保存输出通过转换从blob到其它格式。普通的转换像mean-subtraction和feature-scaling是通过配置data layer来完成。新的输入类型需要开发一个新的data layer来支持。
    
参考附件中的 “caffe源代码解析” “caffe_tutorial” “caffe usage summarization_汤旭”
    
---

# caffe 遇到的一些问题

1. g++ blob_demo.cpp -I /home/hanpengcheng/projects/caffe_pro/caffe-master/include/ -D CPU_ONLY -I /home/hanpengcheng/projects/caffe_pro/caffe-master/.build_release/src/ -L /home/hanpengcheng/projects/caffe_pro/caffe-master/build/lib/ -lcaffe
用于编译新的文件，如下出错：
./a.out: error while loading shared libraries: libcaffe.so.1.0.0-rc3: cannot open shared object file: No such file or directory
解决：
export LD_LIBRARY_PATH=/home/hanpengcheng/projects/caffe_pro/caffe-master/build/lib/:$LD_LIBRARY_PATH

2. g++ blob_demo.cpp -I /home/hanpengcheng/projects/caffe_pro/caffe-master/include/ -D CPU_ONLY -I /home/hanpengcheng/projects/caffe_pro/caffe-master/.build_release/src/ -L /home/hanpengcheng/projects/caffe_pro/caffe-master/build/lib/ -lcaffe
/usr/bin/ld: /tmp/ccMRDzCB.o: undefined reference to symbol '_ZN6google4base21CheckOpMessageBuilder7ForVar2Ev'
//usr/lib/x86_64-linux-gnu/libglog.so.0: error adding symbols: DSO missing from command line
解决：
g++ blob_demo.cpp -I /home/hanpengcheng/projects/caffe_pro/caffe-master/include/ -D CPU_ONLY -I /home/hanpengcheng/projects/caffe_pro/caffe-master/.build_release/src/ -L /home/hanpengcheng/projects/caffe_pro/caffe-master/build/lib/ -lcaffe **-lboost_system -lglog**

3. 编译caffe的时候出现如下undefined erro
//usr/lib/x86_64-linux-gnu/libunwind.so.8: undefined reference to `lzma_index_buffer_decode@XZ_5.0'
//usr/lib/x86_64-linux-gnu/libunwind.so.8: undefined reference to `lzma_index_size@XZ_5.0'
//usr/lib/x86_64-linux-gnu/libunwind.so.8: undefined reference to `lzma_index_uncompressed_size@XZ_5.0'
//usr/lib/x86_64-linux-gnu/libunwind.so.8: undefined reference to `lzma_stream_footer_decode@XZ_5.0'
//usr/lib/x86_64-linux-gnu/libunwind.so.8: undefined reference to `lzma_index_end@XZ_5.0'
//usr/lib/x86_64-linux-gnu/libunwind.so.8: undefined reference to `lzma_stream_buffer_decode@XZ_5.0'
usr/lib/x86_64-linux-gnu/libunwind.so.8: undefined reference to `lzma_index_end@XZ_5.0' collect2: error: ld returned 1 exit status
>1. 解决方案，在~/.bashrc 中增加 export LD_LIBRARY_PATH=/lib/x86_64-linux_gnu:$LD_LIBRARY_PATH
>2. 方案1不可行，可能存在的问题在于 ~/.bashrc 中添加lib的顺序，anaconda2中可能存在相关的lib会影响搜索，上面的library搜索不到

4. ImportError: No module named pydot (caffe)
在利用caffe画网络的时候，(./draw_net.py)会有可能出现上述问题，可能存在的问题是版本依赖的问题
sudo apt-get install graphviz (可能会缺乏graphviz)
解决：
**sudo pip install pydot** 

---

# 实践
参考附件中的读书笔记1-7

---


# 阅读官方文档
**官方文档是最优秀的学习资料。尽管是英文的，但是你要习惯。**
http://caffe.berkeleyvision.org/tutorial/
http://caffe.berkeleyvision.org/






