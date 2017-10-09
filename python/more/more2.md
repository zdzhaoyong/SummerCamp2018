# Python基础 （2）
#### 迭代器
迭代器对象要求支持迭代器协议的对象，在Python中，支持迭代器协议就是实现对象的\_\_iter\_\_()和next()方法。其中\_\_iter\_\_()方法返回迭代器对象本身；next()方法返回容器的下一个元素，在结尾时引发StopIteration异常。
##### \_\_iter\_\_()和next()方法
这两个方法是迭代器最基本的方法，一个用来获得迭代器对象，一个用来获取容器中的下一个元素。
对于可迭代对象，可以使用内建函数iter()来获取它的迭代器对象。
通过iter()方法获得了list的迭代器对象，然后就可以通过next()方法来访问list中的元素了。当容器中没有可访问的元素后，next()方法将会抛出一个StopIteration异常终止迭代器。
其实，当我们使用for语句的时候，for语句就会自动的通过\_\_iter\_\_()方法来获得迭代器对象，并且通过next()方法来获取下一个元素。
##### 迭代器和可迭代对象
对于一个可迭代对象，如果它本身又是一个迭代器对象，就会有下面的 问题，就没有办法支持多次迭代。
为了解决上面的问题，可以分别定义可迭代类型对象和迭代器类型对象；然后可迭代类型对象的\_\_iter\_\_()方法可以获得一个迭代器类型的对象。
```python
class Zrange:
    def __init__(self, n):
        self.n = n
 
    def __iter__(self):
        return ZrangeIterator(self.n)
 
class ZrangeIterator:
    def __init__(self, n):
        self.i = 0
        self.n = n
 
    def __iter__(self):
        return self
 
    def next(self):
        if self.i < self.n:
            i = self.i
            self.i += 1
            return i
        else:
            raise StopIteration()    
 
zrange = Zrange(3)
print zrange is iter(zrange)         
 
print [i for i in zrange]
print [i for i in zrange]
```
***
#### 生成器
在Python中，使用生成器可以很方便的支持迭代器协议。生成器通过生成器函数产生，生成器函数可以通过常规的def语句来定义，但是不用return返回，而是用yield一次返回一个结果，在每个结果之间挂起和继续它们的状态，来自动实现迭代协议。

也就是说，yield是一个语法糖，内部实现支持了迭代器协议，同时yield内部是一个状态机，维护着挂起和继续的状态。
##### 生成器表达式
在开始介绍生成器表达式之前，先看看我们比较熟悉的列表解析( List comprehensions)，列表解析一般都是下面的形式。
>[expr for iter_var in iterable if cond_expr]

生成器表达式的语法和列表解析一样，只不过生成器表达式是被()括起来的，而不是[]
>(expr for iter_var in iterable if cond_expr)

##### 递归生成器
生成器可以向函数一样进行递归使用的，下面看一个简单的例子，对一个序列进行全排列：
```python
def permutations(li):
    if len(li) == 0:
        yield li
    else:
        for i in range(len(li)):
            li[0], li[i] = li[i], li[0]
            for item in permutations(li[1:]):
                yield [li[0]] + item
 
for item in permutations(range(3)):
    print item
    ```
    