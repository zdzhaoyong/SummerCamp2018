# 初识python（2）
## 核心数据结构 -- 字符串
字符串是 Python 中最常用的数据类型。我们可以使用引号('或")来创建字符串。

创建字符串很简单，只要为变量分配一个值即可。例如：

```python
var1 = 'Hello World!'
var2 = "Python Runoob"
```
***
#### Python访问字符串中的值
Python不支持单字符类型，单字符也在Python也是作为一个字符串使用。

Python访问子字符串，可以使用方括号来截取字符串，如下实例：
```python
#!/usr/bin/python

var1 = 'Hello World!'
var2 = "Python Runoob"

print "var1[0]: ", var1[0]
print "var2[1:5]: ", var2[1:5]
```
***
#### Python字符串更新

你可以对已存在的字符串进行修改，并赋值给另一个变量，如下实例：
```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-

var1 = 'Hello World!'

print "更新字符串 :- ", var1[:6] + 'Runoob!'
```
***
#### Python转义字符
在需要在字符中使用特殊字符时，python用反斜杠(\\)转义字符。
***
#### Python字符串运算符
下表实例变量 a 值为字符串 "Hello"，b 变量值为 "Python"：

|操作符  |描述      |
|-------|:--------:|
|+      |字符串连接    |
|*|重复输出字符串|
|[]|通过索引获取字符串中字符|
|[ : ]|截取字符串中的一部分|
|in|成员运算符 - 如果字符串中包含给定的字符返回 True |
|not in |成员运算符 - 如果字符串中不包含给定的字符返回 True |
|r/R|原始字符串 - 原始字符串：所有的字符串都是直接按照字面的意思来使用，没有转义特殊或不能打印的字符。 原始字符串除在字符串的第一个引号前加上字母"r"（可以大小写）以外，与普通字符串有着几乎完全相同的语法。|
|%|格式字符串|
```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-

a = "Hello"
b = "Python"

print "a + b 输出结果：", a + b 
print "a * 2 输出结果：", a * 2 
print "a[1] 输出结果：", a[1] 
print "a[1:4] 输出结果：", a[1:4] 

if( "H" in a) :
    print "H 在变量 a 中" 
else :
    print "H 不在变量 a 中" 

if( "M" not in a) :
    print "M 不在变量 a 中" 
else :
    print "M 在变量 a 中"

print r'\n'
print R'\n'
```
以上程序执行结果为：
```python
a + b 输出结果： HelloPython
a * 2 输出结果： HelloHello
a[1] 输出结果： e
a[1:4] 输出结果： ell
H 在变量 a 中
M 不在变量 a 中
\n
\n
```
***
#### Python 字符串格式化
Python 支持格式化字符串的输出 。尽管这样可能会用到非常复杂的表达式，但最基本的用法是将一个值插入到一个有字符串格式符 %s 的字符串中。

在 Python 中，字符串格式化使用与 C 中 sprintf 函数一样的语法。

如下实例：
```python
#!/usr/bin/python

print "My name is %s and weight is %d kg!" % ('Zara', 21) 
```
以上实例输出结果：
```python
My name is Zara and weight is 21 kg!
```
python字符串格式化符号:

|符号|描述|
|----|:---:|
|%c|格式化字符及其ASCII码|
|%s|格式化字符串|
|%d|格式化整数|
|%u|格式化无符号整型|
|%o|格式化无符号八进制数|
|%x|格式化无符号十六进制数|
|%X|格式化无符号十六进制数（大写）|
|%f|格式化浮点数字，可指定小数点后的精度|
| %e|用科学计数法格式化浮点数|
|%E|作用同%e，用科学计数法格式化浮点数|
|%g|%f和%e的简写|
|   %G| %f 和 %E 的简写|
|  %p|用十六进制数格式化变量的地址|