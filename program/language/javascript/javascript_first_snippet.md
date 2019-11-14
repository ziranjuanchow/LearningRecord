## JavaScript 简介
### JavaScript：直接写入 HTML 输出流
```javascript
document.write("<h1>这是一个标题</h1>");
document.write("<p>这是一个段落。</p>");
```

### JavaScript：对事件的反应
```javascript
<button type="button" onclick="alert('欢迎!')">点我!</button>
```
>alert() 函数在 JavaScript 中并不常用，但它对于代码测试非常方便。\
>onclick 事件只是您即将在本教程中学到的众多事件之一。

### JavaScript：改变 HTML 内容
```html
<script>
function myFunction() {
    x = document.getElementById("demo");  // 找到元素
    x.innerHTML = "Hello JavaScript!";    // 改变内容
}
</script>
<button type="button" onclick="myFunction()">点击这里</button>
```

```javascript
document.getElementById("demo").innerHTML = "Hello JavaScript";
```

经常看到 document.getElementById("some id")。这个方法是 HTML DOM 中定义的。
DOM (Document Object Model)（文档对象模型）是用于访问 HTML 元素的正式 W3C 标准。<font color=red size=4>(没懂)</font>

### JavaScript：改变 HTML 图像
```html
<script>
function changeImage()
{
    element=document.getElementById('myimage')
    if (element.src.match("bulbon"))
    {
        element.src="./images/pic_bulboff.gif";
    }
    else
    {
        element.src="./images/pic_bulbon.gif";
    }
}
</script>
<img id="myimage" onclick="changeImage()" src="./images/pic_bulboff.gif" width="100" height="180">
```
```element.src.match("bulbon")```  匹配DOM <img id="myimage" ......> 里面属性值有没有包含 "bulbon" 这个字符串。

### JavaScript：改变 HTML 样式
改变 HTML 元素的样式，属于改变 HTML 属性的变种。
```HTML
<script>
function myFunction()
{
	x=document.getElementById("demo") // 找到元素
	x.style.color="#ff0000";          // 改变样式
}
</script>
<button type="button" onclick="myFunction()">点击这里</button>
```

### JavaScript：验证输入
JavaScript 常用于验证用户的输入。
```html
<p>请输入数字。如果输入值不是数字，浏览器会弹出提示框。</p>
<input id="demo" type="text">
<script>
function myFunction()
{
	var x=document.getElementById("demo").value;
	if(x==""||isNaN(x))
	{
		alert("不是数字");
	}
}
</script>
<button type="button" onclick="myFunction()">点击这里</button>
```
空格，或者连续空格 isNaN 是判别不出来的。严格判断：
```html
<p>请输入数字。如果输入值不是数字，浏览器会弹出提示框。</p>
<input id="demo" type="text">
<script>
function myFunction()
{
	var x=document.getElementById("demo").value;
	if(isNaN(x)||x.replace(/(^\s*)|(\s*$)/g,"")==""){
		alert("不是数字");
	}
}
</script>
<button type="button" onclick="myFunction()">点击这里</button>
```

## JavaScript 用法

HTML 中的脚本必须位于 <script> 与 </script> 标签之间。\
脚本可被放置在 HTML 页面的 <body> 和 <head> 部分中。
### ```<script>``` 标签
如需在 HTML 页面中插入 JavaScript，请使用 ```<script>``` 标签。\
```<script>``` 和 ```</script>``` 会告诉 JavaScript 在何处开始和结束。\
```<script>``` 和 ```</script>``` 之间的代码行包含了 JavaScript:
```html
<script>
alert("我的第一个 JavaScript");
</script>
```
浏览器会解释并执行位于 ```<script> 和 </script>```之间的 JavaScript 代码 。

### ```<body>``` 中的 JavaScript
```html
<script>
document.write("<h1>这是一个标题</h1>");
document.write("<p>这是一个段落。</p>");
</script>
```

### JavaScript 函数和事件
#### 在 ```<head> 或者 <body>``` 的JavaScript
>可以在 HTML 文档中放入不限数量的脚本。
>脚本可位于 HTML 的 <body> 或 <head> 部分中，或者同时存在于两个部分中。
>通常的做法是把函数放入 <head> 部分中，或者放在页面底部。这样就可以把它们安置到同一处位置，不会干扰页面的内容。

#### ```<head>``` 中的 JavaScript 函数
```html
<!DOCTYPE html>
<html>
<head>
<script>
function myFunction()
{
    document.getElementById("demo").innerHTML="我的第一个 JavaScript 函数";
}
</script>
</head>
<body>
<h1>我的 Web 页面</h1>
<p id="demo">一个段落</p>
<button type="button" onclick="myFunction()">尝试一下</button>
</body>
</html>
```

#### ```<body>``` 中的 JavaScript 函数
```html
<!DOCTYPE html>
<html>
<body>
<h1>我的 Web 页面</h1>
<p id="demo">一个段落</p>
<button type="button" onclick="myFunction()">尝试一下</button>
<script>
function myFunction()
{
    document.getElementById("demo").innerHTML="我的第一个 JavaScript 函数";
}
</script>
</body>
</html>
```

#### 外部的 JavaScript
>也可以把脚本保存到外部文件中。外部文件通常包含被多个网页使用的代码。
>外部 JavaScript 文件的文件扩展名是 .js。
>如需使用外部文件，请在 ```<script>``` 标签的 "src" 属性中设置该 .js 文件：

```html
<!DOCTYPE html>
<html>
<body>
<script src="myScript.js"></script>
</body>
</html>
```

```js
function myFunction()
{
    document.getElementById("demo").innerHTML="我的第一个 JavaScript 函数";
}
```


## JavaScript 输出
>JavaScript 没有任何打印或者输出的函数。

### JavaScript 显示数据
JavaScript 可以通过不同的方式来输出数据
* 使用 window.alert() 弹出警告框。
* 使用 document.write() 方法将内容写到 HTML 文档中。
* 使用 innerHTML 写入到 HTML 元素。
* 使用 console.log() 写入到浏览器的控制台。

#### 使用 window.alert()
```html
<script>
window.alert(5 + 6);
</script>
```

#### 操作 HTML 元素
>如需从 JavaScript 访问某个 HTML 元素，您可以使用 document.getElementById(id) 方法。
>请使用 "id" 属性来标识 HTML 元素，并 innerHTML 来获取或插入元素内容：
```html
<!DOCTYPE html>
<html>
<body>

<h1>我的第一个 Web 页面</h1>

<p id="demo">我的第一个段落</p>

<script>
document.getElementById("demo").innerHTML = "段落已修改。";
</script>

</body>
</html>
```

#### 写到 HTML 文档
```html
<!DOCTYPE html>
<html>
<body>

<h1>我的第一个 Web 页面</h1>

<p>我的第一个段落。</p>

<script>
document.write(Date());
</script>

</body>
</html>
```

>使用 document.write() 仅仅向文档输出写内容。
>如果在<font color=red size=3>文档已完成加载后执行 document.write，整个 HTML 页面将被覆盖。</font>
```html
<!DOCTYPE html>
<html>
<head> 
<meta charset="utf-8"> 
<title>菜鸟教程(runoob.com)</title> 
</head>
<body>
	
<h1>我的第一个 Web 页面</h1>
<p>我的第一个段落。</p>
<button onclick="myFunction()">点我</button>
<script>
function myFunction() 
{
    document.write(Date());
}
</script>
</body>
</html>
```
#### 写到控制台
```html
<!DOCTYPE html>
<html>
<head> 
<meta charset="utf-8"> 
<title>菜鸟教程(runoob.com)</title> 
</head>
<body>

<h1>我的第一个 Web 页面</h1>
<p>
浏览器中(Chrome, IE, Firefox) 使用 F12 来启用调试模式， 在调试窗口中点击 "Console" 菜单。
</p>
<script>
a = 5;
b = 6;
c = a + b;
console.log(c);
var myDate=new Date()
console.log(myDate.toUTCString())
</script>
</body>
</html>
```




## JavaScript 语法
#### JavaScript 字面量
>数字（Number）字面量 可以是整数或者是小数，或者是科学计数(e)。

#### JavaScript 关键字
1|2|3|4
-|-|-|-
abstract | else | instanceof | super
boolean | enum | int | switch
break | export | interface | synchronized
byte | extends | let | this
case | false | long | throw
catch | final | native | throws
char | finally | new | transient
class | float | null | true
const | for | package | try
continue | function | private | typeof
debugger | goto | protected | var
default | if | public | void
delete | implements | return | volatile
do | import | short | while
double | in | static | with

#### JavaScript 注释
```js
// 我不会执行
```
#### JavaScript 数据类型
>JavaScript 有多种数据类型：数字，字符串，数组，对象等等：
```js
var length = 16;                                  // Number 通过数字字面量赋值
var points = x * 10;                              // Number 通过表达式字面量赋值
var lastName = "Johnson";                         // String 通过字符串字面量赋值
var cars = ["Saab", "Volvo", "BMW"];              // Array  通过数组字面量赋值
var person = {firstName:"John", lastName:"Doe"};  // Object 通过对象字面量赋值
```
#### 数据类型的概念
......

#### JavaScript 字母大小写
JavaScript 对大小写是敏感的

## JavaScript 语句
### JavaScript 语句
>JavaScript 语句是发给浏览器的命令。\
>这些命令的作用是告诉浏览器要做的事情。\
>下面的 JavaScript 语句向 id="demo" 的 HTML 元素输出文本 "你好 Dolly" :
```html
document.getElementById("demo").innerHTML = "你好 Dolly";
```

### 分号 ;
......

### JavaScript 代码
>JavaScript 代码是 JavaScript 语句的序列。\
>浏览器按照编写顺序依次执行每条语句。\
>本例向网页输出一个标题和两个段落：
```html
document.getElementById("demo").innerHTML="你好 Dolly";
document.getElementById("myDIV").innerHTML="你最近怎么样?";
```

### JavaScript 代码块
>JavaScript 可以分批地组合起来。\
>代码块以左花括号开始，以右花括号结束。\
>代码块的作用是一并地执行语句序列。\
>本例向网页输出一个标题和两个段落：
```js
function myFunction()
{
    document.getElementById("demo").innerHTML="你好Dolly";
    document.getElementById("myDIV").innerHTML="你最近怎么样?";
}
```

### JavaScript 语句标识符
>JavaScript 语句通常以一个 语句标识符 为开始，并执行该语句。\
>语句标识符是保留关键字不能作为变量名使用。\
>下表列出了 JavaScript 语句标识符 (关键字) ：

语句 | 描述
-|-
break | 用于跳出循环。
catch | 语句块，在 try 语句块执行出错时执行 catch 语句块。
continue | 跳过循环中的一个迭代。
do ... while | 执行一个语句块，在条件语句为 true 时继续执行该语句块。
for | 在条件语句为 true 时，可以将代码块执行指定的次数。
for ... in | 用于遍历数组或者对象的属性（对数组或者对象的属性进行循环操作）。
function | 定义一个函数
if ... else | 用于基于不同的条件来执行不同的动作。
return | 退出函数
switch | 用于基于不同的条件来执行不同的动作。
throw | 抛出（生成）错误 。
try | 实现错误处理，与 catch 一同使用。
var | 声明一个变量。
while | 当条件语句为 true 时，执行语句块。

### 空格
>JavaScript 会忽略多余的空格。您可以向脚本添加空格，来提高其可读性。下面的两行代码是等效的：
```js
var person="Hege";
var person = "Hege";
```

### 对代码行进行折行
>可以在文本字符串中使用反斜杠对代码行进行换行。下面的例子会正确地显示：
```js
document.write("你好 \
世界!");
```
>不过，您不能像这样折行：
```js
document.write \
("你好世界!");
```

## JavaScript 注释
>单行注释以 // 开头。\
>本例用单行注释来解释代码：
```js
// 输出标题：
document.getElementById("myH1").innerHTML="欢迎来到我的主页";
// 输出段落：
document.getElementById("myP").innerHTML="这是我的第一个段落。";
```
>多行注释以 /* 开始，以 */ 结尾。\
>下面的例子使用多行注释来解释代码：
```js
/*
下面的这些代码会输出
一个标题和一个段落
并将代表主页的开始
*/
document.getElementById("myH1").innerHTML="欢迎来到我的主页";
document.getElementById("myP").innerHTML="这是我的第一个段落。";
```

## JavaScript 变量
>变量是用于存储信息的"容器"。
### JavaScript 变量
>与代数一样，JavaScript 变量可用于存放值（比如 x=5）和表达式（比如 z=x+y）。\
>变量可以使用短名称（比如 x 和 y），也可以使用描述性更好的名称（比如 age, sum, >totalvolume）。

* 变量必须以字母开头
* 变量也能以 $ 和 _ 符号开头（不过我们不推荐这么做）
* 变量名称对大小写敏感（y 和 Y 是不同的变量）

### JavaScript 数据类型
>JavaScript 变量还能保存其他数据类型，比如文本值 (name="Bill Gates")。\
>在 JavaScript 中，类似 "Bill Gates" 这样一条文本被称为字符串。\
>JavaScript 变量有很多种类型，但是现在，我们只关注数字和字符串。\
>当您向变量分配文本值时，应该用双引号或单引号包围这个值。\
>当您向变量赋的值是数值时，不要使用引号。如果您用引号包围数值，该值会被作为文本来处>理。
#### Value = undefined
>在计算机程序中，经常会声明无值的变量。未使用值来声明的变量，其值实际上是 undefined。
>在执行过以下语句后，变量 carname 的值将是 undefined：
```js
var carname;
```

## JavaScript 数据类型
>值类型(基本类型)：字符串（String）、数字(Number)、布尔(Boolean)、对空（Null）、未定义（Undefined）、Symbol。\
>引用数据类型：对象(Object)、数组(Array)、函数(Function)。

### JavaScript 拥有动态类型
>JavaScript 拥有动态类型。这意味着相同的变量可用作不同的类型：
```js
var x;               // x 为 undefined
var x = 5;           // 现在 x 为数字
var x = "John";      // 现在 x 为字符串
```

### JavaScript 字符串
>字符串是存储字符（比如 "Bill Gates"）的变量。\
>字符串可以是引号中的任意文本。您可以使用单引号或双引号：
```js
var carname="Volvo XC60";
var carname='Volvo XC60';
```
### JavaScript 数字
>JavaScript 只有一种数字类型。数字可以带小数点，也可以不带：
```js
var x1=34.00;      //使用小数点来写
var x2=34;         //不使用小数点来写
```
>极大或极小的数字可以通过科学（指数）计数法来书写：
```js
var y=123e5;      // 12300000
var z=123e-5;     // 0.00123
```
### JavaScript 布尔
>布尔（逻辑）只能有两个值：true 或 false。

### JavaScript 数组
>下面的代码创建名为 cars 的数组：
```js
var cars=new Array();
cars[0]="Saab";
cars[1]="Volvo";
cars[2]="BMW";
```
>或者 (condensed array):
```js
var cars=new Array("Saab","Volvo","BMW");
```
>或者 (literal array):
```js
var cars=["Saab","Volvo","BMW"];
```
>数组下标是基于零的，所以第一个项目是 [0]，第二个是 [1]，以此类推。

### JavaScript 对象
>对象由花括号分隔。在括号内部，对象的属性以名称和值对的形式 (name : value) 来定义。属性由逗号分隔：
```js
var person={firstname:"John", lastname:"Doe", id:5566};
```
>上面例子中的对象 (person) 有三个属性：firstname、lastname 以及 id。\
>空格和折行无关紧要。声明可横跨多行：
```js
var person={
firstname : "John",
lastname  : "Doe",
id        :  5566
};
```
>对象属性有两种寻址方式：
```js
name=person.lastname;
name=person["lastname"];
```
### Undefined 和 Null
>Undefined 这个值表示变量不含有值。\
>可以通过将变量的值设置为 null 来清空变量。
```js
cars=null;
person=null;
```

### 声明变量类型
>声明新变量时，可以使用关键词 "new" 来声明其类型：
```js
var carname=new String;
var x=      new Number;
var y=      new Boolean;
var cars=   new Array;
var person= new Object;
```

## JavaScript 对象
>JavaScript 对象是拥有属性和方法的数据。

### JavaScript 对象
>在 JavaScript中，几乎所有的事物都是对象。\
><font color=red >JavaScript 对象是变量的容器。</font>

### 对象定义
