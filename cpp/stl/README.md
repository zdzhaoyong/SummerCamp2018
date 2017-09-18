# STL（Standard Template Library）

标签（空格分隔）： SummerCamp2018 CPP

---

[toc]

## 1. 概述
　　STL（Standard Template Library），即标准模板库，是一个高效的C++程序库。STL是ANSI/ISO C++标准函数库的一个子集，它提供了大量可扩展的类模板，包含了诸多在计算机科学领域里所常用的基本数据结构和基本算法，类似于Microsoft Visual C++中的MFC（Microsoft Foundation Class Library）。
　　从逻辑结构和存储结构来看，基本数据结构的数量是有限的。对于其中的数据结构，用户可能需要反复的编写一些类似的的代码，只是为了适应不同数据的类型变化而在细节上有所出入。如果能够将这些经典的数据结构，采用类型参数的形式，设计为通用的类模板和函数模板的形式，允许用户重复利用已有的数据结构构造自己特定类型下的、符合实际需要的数据结构，无疑将简化程序开发，提高软件的开发效率，这就是STL编程的基本设计思想。
　　逻辑层次来看，STL中体现了泛型化程序设计（generic programming）的思想，它提倡使用现有的模板程序代码开发应用程序，是一种代码的重用技术（reusability）。代码重用可以提高软件开发人员的劳动生产率和目标系统质量，是软件工程追求的重要目标。许多程序设计语言通过提供标准库来实现代码重用的机制。STL是一个通用组件库, 它的目标是将常用的数据结构和算法标准化、通用化，这样用户可以直接套用而不用重复开发它们，从而提高程序设计的效率。
　　从实现层次看，STL是一种类型参数化（type parameterized）的程序设计方法，是一个基于模板的标准类库，称之为容器类。每种容器都是一种已经建立完成的标准数据结构。在容器中，放入任何类型的数据，很容易建立一个存储该类型（或类）的数据结构。
　　STL主要由五个部分组成，分别是容器（container）、迭代器（iterator）、适配器（adaptor）、算法（algorithm）以及函数对象（function object）。
　　在STL程序设计中，容器（container）就是通用的数据结构。容器用来承载不同类型的数据对象，就如同现实生活中，人们使用容器用来装载各种物品一样，但C++中的容器还存在一定的“数据加工能力”，它如同一个对数据对象进行加工的模具，可以把不同类型的数据放到这个模具中进行加工处理，形成具有一定共同特性的数据结构。例如将int型、char型或者float型放到队列容器中，就分别生成int队列、char型队列或者float型队列，它们都是队列，具有队列的基本特性，但是具体数据类型是不一样的。
　　STL容器主要包括向量（vector）、列表（list）、队列（deque）、集合（set/ multiset）和映射（map/multimap）等。STL用模板实现了这些最常用的数据结构，并以算法的形式提供了对这些容器类的基本操作。
　　STL中的所有容器都是类模板，是一个已经建立完成的抽象的数据结构，因此可以使用这些容器来存储任何类型的数据，甚至是自己定义的类，而无需自己再定义数据结构。例如利用deque容器，就很容易建立一个队列。


---

## 2. 学习目标与学习方法
### 2.1. 目标
　　掌握STL中常用的容器以及操作，理解这些基本的数据结构的原理，能够设计并实现一个自己的list。

### 2.2. 方法
　　在认真阅读本文档的前提下，新建工程项目，实际上手操作，从而联系使用对应的容器，最后独立完成作业。

---

## 3. 课程内容

### 3.1.　容器的概念
　　所谓STL容器，即是将最常运用的一些数据结构（data structures）实现出来。容器是指容纳特定类型对象的集合。根据数据在容器中排列的特性，容器可概分为序列式（sequence）和关联式（associative）两种。迭代器是一种检查容器内元素并遍历元素的数据类型。它提供类似指针的功能，对容器的内容进行访问。

```c++
#include <iterator>
例如：
std::vector<int> IntVector;
std::vector<int>::iterator first=IntVector.begin();
// begin()得到指向vector开头的Iterator,*first得到开头一个元素的值
std::vector<int>::iterator last=IntVector.end();
// end()得到指向vector结尾的Iterator,*last得到最后一个元素的值
```
 
### 3.2.　序列式容器
　　所谓序列式容器，其中的元素都可序（ordered），但未必有序（sorted）。数组为C++语言内置的序列容器，STL另外提供vector、list、deque（double-ended queue）。它们的差别在于访问元素的方式，以及添加或删除元素相关操作的运行代价。
　　标准库还提供了三种容器适配器（adapter），所谓适配器是根据原始的容器类型所提供的操作，通过定义新的操作接口，来适应基础的容器类型。顺序容器适配器包括stack、queue、priority_queue等序列式容器。其中stack和queue由于只是将deque改头换面而成，技术上被归类为一种配接器（adapter），priority_queue是有优先级管理的队列。
 
**Vector**
#### vector的基本概念
　　vector是标准C++建议替代C数组的动态数组模型，它维护的是一个连续线性空间。
　　vector所采用的数据结构非常简单：线性连续空间。它以两个迭代器start和finish分别指向配置得到的连续空间中目前已被使用的范围，并以迭代器end_of_storage指向整块连续空间（含备用空间）的尾端。
　　vector的实现技术，关键在于其对大小的控制以及重新分配时的数据移动效率。一旦vector原有空间用完，如果客户端每新增一个元素，vector内部就只扩充一个元素的空间，实为不智。因为所谓扩充控件（不论多大），是“配置新空间（malloc）/拷贝移动数据（memcpy）/释放旧空间（free）”的大工程，时间成本很高，应该采用某种未雨绸缪的空间配置策略。
　　注意，所谓动态增加大小，并不是在原空间之后接续新空间（因为无法保证之后尚有可供配置的空间），而是每次再分配原大小两倍的内存空间。因此，对vector的任何操作，一旦引起控件重新配置，指向原vector的所有迭代器就都失效了。
　　由于vector维护的是一个连续线性空间，因此vector迭代器具备普通指针的功能，支持随机存取，即vector提供的是Random Access Iterators。

#### 向量类模板std::vector的成员函数
```c++
#include<vector>
std::vector<type> vec;
std::vector<type> vec(size);
std::vector<type> vec(size,value);
std::vector<type> vec(myvector);
std::vector<type> vec(first,last);
Operators：==、!=、<=、>=、<、>、[]
assign(first,last)：用迭代器first,last所指定的元素取代向量元素
assign(num,val)：用val的num份副本取代向量元素
at(n)：等价于[]运算符，返回向量中位置n的元素，因其有越界检查，故比[]索引访问安全
front()：返回向量中第一个元素的引用
back()：返回向量中最后一个元素的引用
begin()：返回向量中第一个元素的迭代器
end()：返回向量中最后一个元素的下一个迭代器（仅作结束游标，不可解引用）
max_size()：返回向量类型的最大容量（2^30-1=0x3FFFFFFF）
capacity()：返回向量当前开辟的空间大小（<= max_size，与向量的动态内存分配策略相关）
size()：返回向量中现有元素的个数（<=capacity）
clear()：删除向量中所有元素
empty()：如果向量为空，返回真
erase(start,end)：删除迭代器start end所指定范围内的元素
erase(i)：删除迭代器i所指向的元素
erase()返回指向删除的最后一个元素的下一位置的迭代器
insert(i,x)；把x插入到迭代器i所指定的位置之前
insert(i,n,x)：把x的n份副本插入到迭代器i所指定的位置之前
insert(i,start,end)：把迭代器start和end所指定的范围内的值插入到迭代器i所指定的位置之前
push_back(x)：把x推入（插入）到向量的尾部
pop_back()：弹出（删除）向量最后一个元素
rbegin()：返回一个反向迭代器，该迭代器指向的元素越过了向量中的最后一个元素
rend()：返回一个反向迭代器，该迭代器指向向量中第一个元素
reverse()：反转元素顺序
resize(n,x)：把向量的大小改为n,新元素的初值赋为x
swap(vectorref)：交换2个向量的内容
```
 
**List**
#### list的基本概念
　　相对于vector的连续线性空间，list就显得复杂许多，与向量(vector)相比, 它允许快速的插入和删除，且每次插入或删除一个元素，就配置或释放一个元素空间。因此，list对于空间的运用绝对的精准，一点也不浪费。而且，对于任何位置的元素插入或元素移除，list永远是常数时间。
　　list不再能够像vector那样以普通指针作为迭代器，因为其节点不保证在储存空间中连续存在。list迭代器必须有能力指向list的节点，并有能力进行正确的递增、递减、取值、成员存取等操作。所谓“list迭代器正确的递增、递减、取值、成员取用”操作是指，递增时指向下一个节点，递减时指向上一个节点，取值时取的是节点的数据值，成员取用时取用的是节点的成员。
　　list不仅是一个双向链表，而其还是一个环状双向链表。所以它只需要一个指针，便可以完整实现整个链表。由于list是一个双向链表（double linked-list），迭代器必须具备前移、后移的能力，所以list提供的是Bidirectional Iterators。
　　list有一个重要性质：插入操作（insert）和合并操作（splice）都不会造成原有的list迭代器失效。这在vector是不成立的，因为vector的插入操作可能造成记忆体重新配置，导致原有的迭代器全部失效。甚至list的元素删除操作（erase）也只有“指向被删除元素”的那个迭代器失效，其他迭代器不受任何影响。

#### 链表类模板std::list成员函数
```c++
#include<list>
std::list<type> lst;
std::list<type> lst(size);
std::list<type> lst(size,value);
std::list<type> lst(mylist);
std::list<type> lst(first,last);
以下未列出与vector相同的通用操作。
push_front(x)：把元素x推入（插入）到链表头部
pop_front()：弹出（删除）链表首元素
merge(listref)：把listref所引用的链表中的所有元素插入到链表中，可指定合并规则
splice()：把lst连接到pos的位置
remove(val)：删除链表中所有值为val的元素
remove_if(pred)：删除链表中谓词pred为真的元素（谓词即为元素存储和检索的描述，如std::less<>，std::greater<>那么就按降序/升序排列，你也可以定义自己的谓词）
sort()：根据默认的谓词对链表排序
sort(pred)：根据给定的谓词对链表排序
unique()：删除链表中所有重复的元素
unique(pred)：根据谓词pred删除所有重复的元素，使链表中没有重复元素
注意：vector和deque支持随机访问，而list不支持随机访问，因此不支持[]访问！
```
 
**Deque**
#### deque的基本概念
　　vector是单向开口的连续线性空间，deque则是以中双向开口的连续线性空间。所谓双向开口，意思是可以在头尾两端分别做元素的插入和删除操作。从技术的角度而言，vector当然也可以在头尾两端进行操作，但是其头部操作效率奇差、令人无法接受。
　　deque和vector的最大差异，一在于deque允许于常数时间内对头端进行元素的插入或移除操作，二在于deque没有所谓容量（capacity）观念，因为它是动态地以分段连续空间组合而成，随时可以增加一段新的空间并链接起来。换句话说，像vector那样“因旧空间不足而重新配置一块更大空间，然后复制元素，再释放旧空间”这样的事情在deque中是不会发生的。也因此，deque没有必要提供所谓的空间预留（reserved）功能。
　　虽然deque也提供Random Access Iterator，但它的迭代器并不是普通指针，其复杂度和vector不可同日而语，这当然涉及到各个运算层面。因此，除非必要，我们应尽可能选择使用vector而非deque。对deque进行的排序操作，为了最高效率，可将deque先完整复制到一个vector身上，将vector排序后（利用STL的sort算法），再复制回deque。
　　deque是由一段一段的定量连续空间构成。一旦有必要在deque的前端或尾端增加新空间，便配置一段定量的连续空间，串接在整个deque的头端或尾端。deque的最大任务，便是在这些分段的定量连续空间上，维护其整体连续的假象，并提供随机存取的接口。避开了“重新配置、复制、释放”的轮回，代价则是复杂的迭代器架构。

#### 双端队列类模板std::deque成员函数
```c++
#include<deque>
std::deque<type> deq;
std::deque<type> deq(size);
std::deque<type> deq(size,value);
std::deque<type> deq(mydeque);
std::deque<type> deq(first,last);
其成员函数如下：
Operators：[]用来访问双向队列中单个的元素
front()：返回第一个元素的引用
push_front(x)：把元素x推入（插入）到双向队列的头部
pop_front()：弹出（删除）双向队列的第一个元素
back()：返回最后一个元素的引用
push_back(x)：把元素x推入（插入）到双向队列的尾部
pop_back()：弹出（删除）双向队列的最后一个元素
```

**Stack**
#### stack的基本概念
　　stack是一种后进先出（First In Last Out，FILO）的数据结构，它只有一个出口。stack允许新增元素、移除元素、取得最顶端元素。但除了最顶端外，没有任何其他方法可以存取stack的其他元素，换言之，stack不允许随机访问。
　　STL以deque作为stack的底层结构，对deque封闭期头端开口，稍作修改便形成了stack。   
　　将元素插入stack的操作称为push，将元素弹出stack的操作称为pop。stack所有元素的进出都必须符合“后进先出”的条件，只有stack顶端的元素，才有机会被外界取用。stack不提供走访功能，也不提供迭代器。

#### 容器适配器堆栈类std::stack成员函数
```c++
#include<stack>
stack实现后进先出的操作
std::stack<type,container> stk;
type为堆栈操作的数据类型
container为实现堆栈所用的容器类型，默认基于deque，还可以为std::vector和std::list
例如std::stack<int,std::list<int>> IntStack;
其成员函数如下：
top()：返回顶端元素的引用
push(x)：将元素压入栈（顶）
pop()：弹出（删除）顶端元素
```
 
**Queue**
#### queue的基本概念
queue是一种先进先出（First In First Out，FIFO）的数据结构，它有两个出口。queue允许新增元素、移除元素、从最底端加入元素、取得最顶端元素。但除了最底端可以加入、最顶端可以取出，没有任何其他方法可以存取queue的其他元素。换言之，queue不支持随机访问。
STL以deque作为queue的底层结构，对deque封闭其底端的出口和前端的入口，稍作修改便形成了queue。

#### 容器适配器队列类std::queue成员函数
```c++
#include<queue>
queue实现先进先出的操作
std::queue<type,container> que;
type为队列操作的数据类型
container为实现队列所用的容器类型，只能为提供了push_front操作的std::deque或std::list，默认基于std::deque
其成员函数如下：
front()：返回队首元素的引用
back()：返回队尾元素的引用
push(x)：把元素x推入（插入）到队尾
pop()：队首元素出列（弹出（删除）队首元素）
```
 
**Priority_queue**
#### priority_queue的基本概念
priority_queue为优先级队列，它允许用户为队列中存储的元素设置优先级。这种队列不是直接将新元素放置在队列尾部，而是放置在比它优先级低的元素前面，即提供了一种插队策略。标准库默认使用<操作符来确定他们之间的优先级关系。即权重大的排在队首。
使用priority_queue时，包含<queue>文件。

#### 容器适配器队列类std::priority_queue成员函数
```c++
#include<queue>
priority_queue实现先进先出的操作
std::priority_queue<type, container, comp> pri_que;
type为队列操作的数据类型
container为实现队列所用的容器类型，可以为std::vector,std::deque，默认基于deque
comp为排队策略，默认为std::less<>，即插到小于它的元素前
例如std::priority_queue<int,std::vector<int>,std::greater<int> > IntPriQue;
其成员函数如下：
top()：返回队首（优先级最高）元素的引用
push(x)：将元素推入（按插队策略插排）队列（尾部）
pop()：弹出（删除）队首（优先级最高）元素
```
 
### 3.3.　关联式容器
　　所谓关联式容器，概念上类似关联式数据库（实际上则简单许多）：每项数据（元素）包含一个键值（key）和一个实值（value）。当元素被插入到关联式容器中时，容器内部数据结构（可能是RB-tree，也可能是hash-table）便依照其键值大小，以某种特定规则将这个元素放置于适当位置。关联式容器没有所谓头尾（只有最大元素和最小元素），所以不会有push_back()，push_front()，pop_back()，pop_front()，begin()，end()这样的操作。
　　一般而言，关联式容器的内部结构是一个balanced binary tree（平衡二叉树），以便获得良好的搜索效率。balanced binary tree有很多种类型，包括AVL-tree、RB-tree、AA-tree，其中广泛运用于STL的是RB-tree（红黑树）。
　　标准的STL关联式容器分为set（集合）和map（映射类）两大类，以及这两大类的衍生体multiset（多键集合）和multimap（多键映射表）。这些容器的底层机制均以RB-tree完成（红黑树）。RB-tree也是一个独立容器，但并不开放给外界使用。
　　此外，SGI STL还提供了一个不在标准规格之列的关联式容器：hash table(散列表，哈希表)，以及以此hash table为底层机制而完成的hash_set（散列集合）、hash_map（散列映射表）、hash_multiset（散列多键集合）、hash_multimap（散列多键映射表）。
 
**Map**
#### 关联式容器std::map成员函数
```c++
#include<map>
map建立key-value映射
std::map<key, value> mp;
std::map<key, value, comp> mp;
key为键值
value为映射值
comp可选，为键值对存放策略，例如可为std::less<>，键值映射对将按键值从小到大存储
其成员函数如下：
count()：返回map中键值等于key的元素的个数
equal_range()：函数返回两个迭代器——一个指向第一个键值为key的元素，另一个指向最后一个键值为key的元素
erase(i)：删除迭代器所指位置的元素（键值对）
lower_bound()：返回一个迭代器，指向map中键值>=key的第一个元素
upper_bound()：函数返回一个迭代器，指向map中键值>key的第一个元素
find(key)：返回键值为key的键值对迭代器，如果没有该映射则返回结束游标end()
注意map的[]操作符，当试图对于不存在的key进行引用时，将新建键值对，值为空。
```

### 3.4.　STL中常见容器的优缺点

**verctor**
　　vector类似于C语言中的数组，它维护一段连续的内存空间，具有固定的起始地址，因而能非常方便地进行随机存取，即 [] 操作符，但因为它的内存区域是连续的，所以在它中间插入或删除某个元素，需要复制并移动现有的元素。此外，当被插入的内存空间不够时，需要重新申请一块足够大的内存并进行内存拷贝。值得注意的是，vector每次扩容为原来的两倍，对小对象来说执行效率高，但如果遇到大对象，执行效率就低了。
**list**
　　list类似于C语言中的双向链表，它通过指针来进行数据的访问，因此维护的内存空间可以不连续，这也非常有利于数据的随机存取，因而它没有提供 [] 操作符重载。
**deque**
　　deque类似于C语言中的双向队列，即两端都可以插入或者删除的队列。queue支持 [] 操作符，也就是支持随机存取，而且跟vector的效率相差无几。它支持两端的操作：push_back,push_front,pop_back,pop_front等，并且在两端操作上与list的效率也差不多。或者我们可以这么认为，deque是vector跟list的折中。
**map**
　　map类似于数据库中的１:１关系，它是一种关联容器，提供一对一(C++ primer中文版中将第一个译为键，每个键只能在map中出现一次，第二个被译为该键对应的值)的数据处理能力，这种特性了使得map类似于数据结构里的红黑二叉树。
**multimap**
　　multimap类似于数据库中的１:Ｎ关系，它是一种关联容器,提供一对多的数据处理能力。

**总结**

> * 如果需要高效的随机存取，不在乎插入和删除的效率，使用vector；
> * 如果需要大量的插入和删除元素，不关心随机存取的效率，使用list；
> * 如果需要随机存取，并且关心两端数据的插入和删除效率，使用deque；
> * 如果打算存储数据字典，并且要求方便地根据key找到value，一对一的情况使用map，一对多的情况使用multimap；

### 3.5.　迭代器

　　迭代器提供对一个容器中的对象的访问方法，并且定义了容器中对象的范围。迭代器就如同一个指针。事实上，C++的指针也是一种迭代器。但是，迭代器不仅仅是指针，因此你不能认为他们一定具有地址值。例如，一个数组索引，也可以认为是一种迭代器。
　　迭代器有各种不同的创建方法。程序可能把迭代器作为一个变量创建。一个STL 容器类可能为了使用一个特定类型的数据而创建一个迭代器。作为指针，必须能够使用*操作符类获取数据。你还可以使用其他数学操作符如++。典型的，++操 作符用来递增迭代器，以访问容器中的下一个对象。如果迭代器到达了容器中的最后一个元素的后面，则迭代器变成past-the-end值。使用一个 past-the-end值得指针来访问对象是非法的，就好像使用NULL或为初始化的指针一样。
　　STL不保证可以从另一个迭代器来抵达一个迭代器。例如，当对一个集合中的对象排序时，如果你在不同的结构中指定了两个迭代器，第二个迭代器无法从第一个迭代器抵达，此时程序注定要失败。这是STL灵活性的一个代价。STL不保证检测毫无道理的错误。

**迭代器的类型**

　　对于STL数据结构和算法，你可以使用五种迭代器。下面简要说明了这五种类型：
　　
> * Input iterators 提供对数据的只读访问。
> * Output iterators 提供对数据的只写访问
> * Forward iterators 提供读写操作，并能向前推进迭代器。
> * Bidirectional iterators提供读写操作，并能向前和向后操作。
> * Random access iterators提供读写操作，并能在数据中随机移动。

　　尽管各种不同的STL 实现细节方面有所不同，还是可以将上面的迭代器想象为一种类继承关系。从这个意义上说，下面的迭代器继承自上面的迭代器。由于这种继承关系，你可以将一个 Forward迭代器作为一个output或input迭代器使用。同样，如果一个算法要求是一个bidirectional 迭代器，那么只能使用该种类型和随机访问迭代器。



---

## 4.　作业

**目标：** 自己实现一个基本的list模板类, 修改exercise下的mylist.h使得程序编译通过并在最后输出PASSED.
**备注：** 原则上不允许改动main.cpp，如没有明确思路，可参考下列实现：


```c++
//ListNode.h
typedef int Rank; //秩

#define ListNodePosi(T) ListNode<T>* //列表节点位置

template <typename T> 
struct ListNode { //列表节点模板类（以双向链表形式表现）
//成员
    T data; //数值
    ListNodePosi(T) pred; //前驱
    ListNodePosi(T) succ; //后继
//构造函数
    ListNode() {}
    ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
        : data(e), pred(p), succ(s) {} //默认构造器
//操作接口
    ListNodePosi(T) insertAsPred(T const& e); //紧靠当前节点之前插入新节点
    ListNOdePosi(T) insertAsSucc(T const& e); //紧随当前节点之后插入新节点
}
```

```c++
//List.h
#include "ListNode.h"

template <typename T> 
class List {
private:
   int _size; ListNodePosi(T) header; ListNodePosi(T) trailer; //规模、头哨兵、尾哨兵

protected:
   void init(); //列表创建时的初始化
   int clear(); //清除所有节点
   void copyNodes ( ListNodePosi(T), int ); //复制列表中自位置p起的n项
   void merge ( ListNodePosi(T)&, int, List<T>&, ListNodePosi(T), int ); //归并
   void mergeSort ( ListNodePosi(T)&, int ); //对从p开始连续的n个节点归并排序
   void selectionSort ( ListNodePosi(T), int ); //对从p开始连续的n个节点选择排序
   void insertionSort ( ListNodePosi(T), int ); //对从p开始连续的n个节点插入排序

public:
// 构造函数
   List() { init(); } //默认
   List ( List<T> const& L ); //整体复制列表L
   List ( List<T> const& L, Rank r, int n ); //复制列表L中自第r项起的n项
   List ( ListNodePosi(T) p, int n ); //复制列表中自位置p起的n项
// 析构函数
   ~List(); //释放（包含头、尾哨兵在内的）所有节点
// 只读访问接口
   Rank size() const { return _size; } //规模
   bool empty() const { return _size <= 0; } //判空
   T& operator[] ( Rank r ) const; //重载，支持循秩访问（效率低）
   ListNodePosi(T) first() const { return header->succ; } //首节点位置
   ListNodePosi(T) last() const { return trailer->pred; } //末节点位置
   bool valid ( ListNodePosi(T) p ) //判断位置p是否对外合法
   { return p && ( trailer != p ) && ( header != p ); } //将头、尾节点等同于NULL
   int disordered() const; //判断列表是否已排序
   ListNodePosi(T) find ( T const& e ) const //无序列表查找
   { return find ( e, _size, trailer ); }
   ListNodePosi(T) find ( T const& e, int n, ListNodePosi(T) p ) const; //无序区间查找
   ListNodePosi(T) search ( T const& e ) const //有序列表查找
   { return search ( e, _size, trailer ); }
   ListNodePosi(T) search ( T const& e, int n, ListNodePosi(T) p ) const; //有序区间查找
   ListNodePosi(T) selectMax ( ListNodePosi(T) p, int n ); //在p及其n-1个后继中选出最大者
   ListNodePosi(T) selectMax() { return selectMax ( header->succ, _size ); } //整体最大者
// 可写访问接口
   ListNodePosi(T) insertAsFirst ( T const& e ); //将e当作首节点插入
   ListNodePosi(T) insertAsLast ( T const& e ); //将e当作末节点插入
   ListNodePosi(T) insertA ( ListNodePosi(T) p, T const& e ); //将e当作p的后继插入
   ListNodePosi(T) insertB ( ListNodePosi(T) p, T const& e ); //将e当作p的前驱插入
   T remove ( ListNodePosi(T) p ); //删除合法位置p处的节点,返回被删除节点
   void merge ( List<T>& L ) { merge ( first(), size, L, L.first(), L._size ); } //全列表归并
   void sort ( ListNodePosi(T) p, int n ); //列表区间排序
   void sort() { sort ( first(), _size ); } //列表整体排序
   int deduplicate(); //无序去重
   int uniquify(); //有序去重
   void reverse(); //前后倒置（习题）
// 遍历
   void traverse ( void (* ) ( T& ) ); //遍历，依次实施visit操作（函数指针，只读或局部性修改）
   template <typename VST> //操作器
   void traverse ( VST& ); //遍历，依次实施visit操作（函数对象，可全局性修改）
}; //List

```
<!---以下是提供目录显示的代码，保留以自动生成目录--->
<link rel="stylesheet" href="http://yandex.st/highlightjs/6.2/styles/googlecode.min.css">
<script src="http://code.jquery.com/jquery-1.7.2.min.js"></script>
<script src="http://yandex.st/highlightjs/6.2/highlight.min.js"></script>
<script>hljs.initHighlightingOnLoad();</script>
<script type="text/javascript">
 $(document).ready(function(){
 $("h2,h3,h4,h5,h6").each(function(i,item){
 var tag = $(item).get(0).localName;
 $(item).attr("id","wow"+i);
 $("#category").append('<a class="new'+tag+'" href="#wow'+i+'">'+$(this).text()+'</a></br>');
 $(".newh2").css("margin-left",0);
 $(".newh3").css("margin-left",20);
 $(".newh4").css("margin-left",40);
 $(".newh5").css("margin-left",60);
 $(".newh6").css("margin-left",80);
 });
 });
</script>
<div id="category"></div>



