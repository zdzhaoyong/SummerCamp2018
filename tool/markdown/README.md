# Markdown 教程

> Step1:  在浏览器上打开　[在线版编辑器 -- 马克飞象](https://maxiang.io/)
> Step2:  本教程正好是用Markdown写的，把教程源文件["README.md"](./README.md) 复制粘贴到马克飞象网页的编辑栏
> Step2:  对照左边的源码和右边的排版效果来学习．

## Markdown简介

> Markdown 是一种轻量级标记语言，它允许人们使用易读易写的纯文本格式编写文档，然后转换成格式丰富的HTML页面。    

Markdown 是一种轻量级的「标记语言」，它的优点很多，目前也被越来越多的写作爱好者，撰稿者广泛使用。看到这里请不要被「标记」、「语言」所迷惑，Markdown 的语法十分简单。常用的标记符号也不超过十个，这种相对于更为复杂的 HTML 标记语言来说，Markdown 可谓是十分轻量的，学习成本也不需要太多，且一旦熟悉这种语法规则，会有一劳永逸的效果。

Markdown具有一系列衍生版本，用于扩展Markdown的功能（如表格、脚注、内嵌HTML等等），这些功能原初的Markdown尚不具备，它们能让Markdown转换成更多的格式，例如LaTeX，Docbook。Markdown增强版中比较有名的有Markdown Extra、MultiMarkdown、 Maruku等。这些衍生版本要么基于工具，如Pandoc；要么基于网站，如GitHub和Wikipedia，在语法上基本兼容，但在一些语法和渲染效果上有改动。

—— [Mastering Markdown](https://guides.github.com/features/mastering-markdown/)

## Markdown 编辑器
1. [在线版编辑器 -- 马克飞象](https://maxiang.io/)     (推荐使用在线网页版编辑器)
2. [在线版编辑器 -- Madoko](https://www.madoko.net/editor.html#tab=2)
3. [离线编辑器有道云笔记-- Windows系统](http://note.youdao.com/index.html?vendor=unsilent14)
4.  离线编辑器ReText -- Linux系统  (**sudo apt-get install retext**  or  **sudo apt-get install ReText** )
5.  GitHub : [Mastering Markdown](https://guides.github.com/features/mastering-markdown/)  


## 常用语法　(一般编辑器都支持的语法)

### 标题

“#” 后最好加个"空格"。除此之外，还有 5 级标题，依次有不同的字体大小，即

```
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题
###### 六级标题
```

### 链接
Markdown 支持两种形式的链接语法： 行内式和参考式两种形式。不管是哪一种，链接文字都是用 [方括号] 来标记。

要建立一个行内式的链接，只要在方块括号后面紧接着圆括号并插入网址链接即可，如果你还想要加上链接的 title 文字，只要在网址后面，用双引号把 title 文字包起来即可，例如：

```
This is [an example](https://guides.github.com/features/mastering-markdown/) inline link.
```
This is [an example](https://guides.github.com/features/mastering-markdown/) inline link.

参考式的链接是在链接文字的括号后面再接上另一个方括号，而在第二个方括号里面要填入用以辨识链接的标记：

```
This is [an example][id] reference-style link.
```

This is [an example][id] reference-style link.
[id]: http://example.com/  "Optional Title Here"

接着，在文件的任意处，你可以把这个标记的链接内容定义出来：

```
[id]: http://example.com/  "Optional Title Here"
```

### 代码块

``` python
@requires_authorization
def somefunc(param1='', param2=0):
    '''A docstring'''
    if param1 > param2: # interesting
        print 'Greater'
    return (param2 - param1 + 1) or None
class SomeClass:
    pass
>>> message = '''interpreter
... prompt'''
```

```javascript
function fancyAlert(arg) {
  if(arg) {
    $.facebox({div:'#foo'})
  }
}
```

### 表格

```
| Item      |    Value | Qty  |
| :-------- | --------:| :--: |
| Computer  | 1600 USD |  5   |
| Phone     |   12 USD |  12  |
| Pipe      |    1 USD | 234  |
```

| Item      |    Value | Qty  |
| :-------- | --------:| :--: |
| Computer  | 1600 USD |  5   |
| Phone     |   12 USD |  12  |
| Pipe      |    1 USD | 234  |

### 列表

Sometimes you want numbered lists:

```
1. One
2. Two
3. Three

Sometimes you want bullet points:

* Start a line with a star
* Profit!

Alternatively,

- Dashes work just as well
- And if you have sub points, put two spaces before the dash or star:
  - Like this
  - And this
```

1. One
2. Two
3. Three

Sometimes you want bullet points:

* Start a line with a star
* Profit!

Alternatively,

- Dashes work just as well
- And if you have sub points, put two spaces before the dash or star:
  - Like this
  - And this



### 图片

If you want to embed images, this is how you do it:

```
![Image of Yaktocat](https://octodex.github.com/images/yaktocat.png)
```

![Image of Yaktocat](https://octodex.github.com/images/yaktocat.png)

### 复选框
```
- [x] This is a complete item
- [ ] This is an incomplete item
```

- [x] This is a complete item
- [ ] This is an incomplete item


### 引用

引用需要在被引用的文本前加上 > 符号。
这是一个引用：
```
> Coffee. The finest organic suspension ever devised... I beat the Borg with it.
> - Captain Janeway
```

> Coffee. The finest organic suspension ever devised... I beat the Borg with it.
> - Captain Janeway

引用的多层嵌套：
```
>>> 请问 Markdwon 怎么用？ - 小白
>> 自己看教程！ - 愤青
> 教程在哪？ - 小白
```

>>> 请问 Markdwon 怎么用？ - 小白
>> 自己看教程！ - 愤青
> 教程在哪？ - 小白

### 强调

Markdown 的粗体和斜体也非常简单，用两个 * 包含一段文本就是粗体的语法，用一个 * 包含一段文本就是斜体的语法。

```
*This text will be italic*
_This will also be italic_

**This text will be bold**
__This will also be bold__

_You **can** combine them_
```

*This text will be italic*
_This will also be italic_

**This text will be bold**
__This will also be bold__

_You **can** combine them_


### 分隔线

你可以在一行中用三个以上的星号、减号、底线来建立一个分隔线，行内不能有其他东西。你也可以在星号或是减号中间插入空格。下面每种写法都可以建立分隔线：

```

* * *

***

*****

- - -

---------------------------------------

```

* * *

***

*****

- - -

---------------------------------------


### 

### 层次

比如写个读书笔记，你得

```
#### 第一章
1. 第一节
2. 第二节(你不用敲 "2"，自动就有了）
    * 第一小节（推荐每层次缩进四个空格）
        * 小小节 1
        * 小小节 
    * 第二小节
```

#### 第一章
1. 第一节
2. 第二节(你不用敲 "2"，自动就有了）
    * 第一小节（推荐每层次缩进四个空格）
        * 小小节 1
        * 小小节 
    * 第二小节
    

## 特殊语法（很多编辑器不支持，GitHub不支持）


### LaTeX 公式

```
质能守恒方程可以用一个很简洁的方程式 $E=mc^2$ 来表达。
```
显示效果：

> 质能守恒方程可以用一个很简洁的方程式 $E=mc^2$ 来表达。

```
$$\sum_{i=1}^n a_i=0$$
$$f(x_1,x_x,\ldots,x_n) = x_1^2 + x_2^2 + \cdots + x_n^2 $$
$$\sum^{j-1}_{k=0}{\widehat{\gamma}_{kj} z_k}$$
```
显示效果：

> $$\sum_{i=1}^n a_i=0$$
$$f(x_1,x_x,\ldots,x_n) = x_1^2 + x_2^2 + \cdots + x_n^2 $$
$$\sum^{j-1}_{k=0}{\widehat{\gamma}_{kj} z_k}$$

### 课程作业

> 不同编辑器对语法的支持性不一样，更多语法请看本教程的附件 "Markdown 语法手册.pdf"．
> markdown支持嵌入html语言，但是为了保证统一性，尽可能只使用标准语法和markdown原生支持的语法．

学习完本课程后，大家根据自己的兴趣用markdown写一篇文章，要求用到上面介绍的常用语法．　
书写风格可以参考[马克飞象](https://maxiang.io/#/?id=readme)和[HandsFree Object Pick Place](https://github.com/HANDS-FREE/HANDS-FREE.github.io/wiki/8.3-Object-Pick-Place/_edit)
　
