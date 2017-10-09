#初识python（6）
##表达式与运算符
本章节主要说明Python的运算符。举个简单的例子 4 +5 = 9 。 例子中，4 和 5 被称为操作数，"+" 称为运算符。

Python语言支持以下类型的运算符:
- 算术运算符
-    比较（关系）运算符
-   赋值运算符
-    逻辑运算符
-    位运算符
-    成员运算符
-    身份运算符
-    运算符优先级
***
####算术运算符
|运算符|描述|
|---|
|+|	加 - 两个对象相加
|-	|减 - 得到负数或是一个数减去另一个数
|*|	乘 - 两个数相乘或是返回一个被重复若干次的字符串
|/|	除 - x除以y
|%|	取模 - 返回除法的余数
|`**`|	幂 - 返回x的y次幂
|//|	取整除 - 返回商的整数部分

以下实例演示了Python所有算术运算符的操作：
```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
a = 21
b = 10
c = 0
 
c = a + b
print "1 - c 的值为：", c
 
c = a - b
print "2 - c 的值为：", c 
 
c = a * b
print "3 - c 的值为：", c 
 
c = a / b
print "4 - c 的值为：", c 
 
c = a % b
print "5 - c 的值为：", c
 
# 修改变量 a 、b 、c
a = 2
b = 3
c = a**b 
print "6 - c 的值为：", c
 
a = 10
b = 5
c = a//b 
print "7 - c 的值为：", c
```
***
####比较运算符
|运算符|描述|
|---|
|==	|等于 - 比较对象是否相等
|!=|	不等于 - 比较两个对象是否不相等
|<>	|不等于 - 比较两个对象是否不相等
|>|	大于 - 返回x是否大于y
|<|	小于 - 返回x是否小于y。所有比较运算符返回1表示真，返回0表示假。这分别与特殊的变量True和False等价。注意，这些变量名的大写。
|>=|	大于等于 - 返回x是否大于等于y。
|<=|	小于等于 - 返回x是否小于等于y。

以下实例演示了Python所有比较运算符的操作：
```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
a = 21
b = 10
c = 0
 
if ( a == b ):
   print "1 - a 等于 b"
else:
   print "1 - a 不等于 b"
 
if ( a != b ):
   print "2 - a 不等于 b"
else:
   print "2 - a 等于 b"
 
if ( a <> b ):
   print "3 - a 不等于 b"
else:
   print "3 - a 等于 b"
 
if ( a < b ):
   print "4 - a 小于 b" 
else:
   print "4 - a 大于等于 b"
 
if ( a > b ):
   print "5 - a 大于 b"
else:
   print "5 - a 小于等于 b"
 
# 修改变量 a 和 b 的值
a = 5
b = 20
if ( a <= b ):
   print "6 - a 小于等于 b"
else:
   print "6 - a 大于  b"
 
if ( b >= a ):
   print "7 - b 大于等于 a"
else:
   print "7 - b 小于 a"
```
***
####赋值运算符
|运算符|描述|
|---|
|=	|简单的赋值运算符
|+=|	加法赋值运算符
|-=|	减法赋值运算符
|`*=`|	乘法赋值运算符
|/=|	除法赋值运算符
|%=|	取模赋值运算符
|`**=`|	幂赋值运算符
|//=|	取整除赋值运算符


以下实例演示了Python所有赋值运算符的操作：
```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
a = 21
b = 10
c = 0
 
c = a + b
print "1 - c 的值为：", c
 
c += a
print "2 - c 的值为：", c 
 
c *= a
print "3 - c 的值为：", c 
 
c /= a 
print "4 - c 的值为：", c 
 
c = 2
c %= a
print "5 - c 的值为：", c
 
c **= a
print "6 - c 的值为：", c
 
c //= a
print "7 - c 的值为：", c
```
***
####位运算符
 按位运算符是把数字看作二进制来进行计算的。Python中的按位运算法则如下：

下表中变量 a 为 60，b 为 13，二进制格式如下：
```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
a = 60            # 60 = 0011 1100 
b = 13            # 13 = 0000 1101 
c = 0
 
c = a & b;        # 12 = 0000 1100
print "1 - c 的值为：", c
 
c = a | b;        # 61 = 0011 1101 
print "2 - c 的值为：", c
 
c = a ^ b;        # 49 = 0011 0001
print "3 - c 的值为：", c
 
c = ~a;           # -61 = 1100 0011
print "4 - c 的值为：", c
 
c = a << 2;       # 240 = 1111 0000
print "5 - c 的值为：", c
 
c = a >> 2;       # 15 = 0000 1111
print "6 - c 的值为：", c
```
***
####逻辑运算符
|运算符|逻辑表达式|描述
|---|
|and|	x and y	|布尔"与" - 如果 x 为 False，x and y 返回 False，否则它返回 y 的计算值。
|or|	x or y	|布尔"或" - 如果 x 是非 0，它返回 x 的值，否则它返回 y 的计算值。
|not|	not x	|布尔"非" - 如果 x 为 True，返回 False 。如果 x 为 False，它返回 True。

以上实例输出结果：
```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
a = 10
b = 20
 
if ( a and b ):
   print "1 - 变量 a 和 b 都为 true"
else:
   print "1 - 变量 a 和 b 有一个不为 true"
 
if ( a or b ):
   print "2 - 变量 a 和 b 都为 true，或其中一个变量为 true"
else:
   print "2 - 变量 a 和 b 都不为 true"
 
# 修改变量 a 的值
a = 0
if ( a and b ):
   print "3 - 变量 a 和 b 都为 true"
else:
   print "3 - 变量 a 和 b 有一个不为 true"
 
if ( a or b ):
   print "4 - 变量 a 和 b 都为 true，或其中一个变量为 true"
else:
   print "4 - 变量 a 和 b 都不为 true"
 
if not( a and b ):
   print "5 - 变量 a 和 b 都为 false，或其中一个变量为 false"
else:
   print "5 - 变量 a 和 b 都为 true"
```
***
####成员运算符
除了以上的一些运算符之外，Python还支持成员运算符，测试实例中包含了一系列的成员，包括字符串，列表或元组

|运算符|描述|
|---|
|in	|如果在指定的序列中找到值返回 True，否则返回 False。
|not |in	如果在指定的序列中没有找到值返回 True，否则返回 False。

以下实例演示了Python所有成员运算符的操作：
```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
a = 10
b = 20
list = [1, 2, 3, 4, 5 ];
 
if ( a in list ):
   print "1 - 变量 a 在给定的列表中 list 中"
else:
   print "1 - 变量 a 不在给定的列表中 list 中"
 
if ( b not in list ):
   print "2 - 变量 b 不在给定的列表中 list 中"
else:
   print "2 - 变量 b 在给定的列表中 list 中"
 
# 修改变量 a 的值
a = 2
if ( a in list ):
   print "3 - 变量 a 在给定的列表中 list 中"
else:
   print "3 - 变量 a 不在给定的列表中 list 中"
```
***
####身份运算符
|运算符|	描述|
|---|
|is|	is 是判断两个标识符是不是引用自一个对象
|is |not	is not 是判断两个标识符是不是引用自不同对象

以下实例演示了Python所有身份运算符的操作：
```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
a = 20
b = 20
 
if ( a is b ):
   print "1 - a 和 b 有相同的标识"
else:
   print "1 - a 和 b 没有相同的标识"
 
if ( a is not b ):
   print "2 - a 和 b 没有相同的标识"
else:
   print "2 - a 和 b 有相同的标识"
 
# 修改变量 b 的值
b = 30
if ( a is b ):
   print "3 - a 和 b 有相同的标识"
else:
   print "3 - a 和 b 没有相同的标识"
 
if ( a is not b ):
   print "4 - a 和 b 没有相同的标识"
else:
   print "4 - a 和 b 有相同的标识"
```
注意： 
> s 与 `==` 区别：
> is 用于判断两个变量引用对象是否为同一个， == 用于判断引用变量的值是否相等。

***
####运算符优先级
以下表格列出了从最高到最低优先级的所有运算符：

|运算符	|描述|
|---|
|`**`| 	指数 (最高优先级)
|~ + -| 	按位翻转, 一元加号和减号 (最后两个的方法名为 +@ 和 -@)
|* / % //| 	乘，除，取模和取整除
|+ -| 	加法减法
|>> <<| 	右移，左移运算符
|&| 	位 'AND'
|^ \| 	位运算符
|<= < > >=| 	比较运算符
|<> == !=| 	等于运算符
|= %= /= //= -= += \*= \*\*= |	赋值运算符
|is is not 	|身份运算符
|in not in 	|成员运算符
|not or and| 	逻辑运算符

以下实例演示了Python所有运算符优先级的操作：
```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
a = 20
b = 10
c = 15
d = 5
e = 0
 
e = (a + b) * c / d       #( 30 * 15 ) / 5
print "(a + b) * c / d 运算结果为：",  e
 
e = ((a + b) * c) / d     # (30 * 15 ) / 5
print "((a + b) * c) / d 运算结果为：",  e
 
e = (a + b) * (c / d);    # (30) * (15/5)
print "(a + b) * (c / d) 运算结果为：",  e
 
e = a + (b * c) / d;      #  20 + (150/5)
print "a + (b * c) / d 运算结果为：",  e
```
