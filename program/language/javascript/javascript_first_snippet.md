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
>你可以使用字符来定义和创建 JavaScript 对象:
```js
var person = {firstName:"John", lastName:"Doe", age:50, eyeColor:"blue"};
```
>定义 JavaScript 对象可以跨越多行，空格跟换行不是必须的：
```js
var person = {
    firstName:"John",
    lastName:"Doe",
    age:50,
    eyeColor:"blue"
};
```

### 对象属性
><font color=red >可以说 "JavaScript 对象是变量的容器"。</font>\
>但是，我们通常认为 "JavaScript 对象是键值对的容器"。\
>键值对通常写法为 name : value (键与值以冒号分割)。\
>键值对在 JavaScript 对象通常称为 对象属性。\
><font color=red >JavaScript 对象是属性变量的容器。</font>
>* 对象键值对的写法类似于：
>* PHP 中的关联数组
>* Python 中的字典
>* C 语言中的哈希表
>* Java 中的哈希映射
>* Ruby 和 Perl 中的哈希表

### 访问对象属性
>你可以通过两种方式访问对象属性:
```js
person.lastName;
person["lastName"];
```

### 对象方法
>对象的方法定义了一个函数，并作为对象的属性存储。\
>对象方法通过添加 () 调用 (作为一个函数)。\
>该实例访问了 person 对象的 fullName() 方法:
```js
name = person.fullName();
```
如果你要访问 person 对象的 fullName 属性，它将作为一个定义函数的字符串返回：
```js
name = person.fullName;
```
><font color=red >JavaScript 对象是属性和方法的容器。</font>

### 访问对象方法

```js
//可以使用以下语法创建对象方法：
methodName : function() { code lines }
//可以使用以下语法访问对象方法：
objectName.methodName()
```
>通常 fullName() 是作为 person 对象的一个方法， fullName 是作为一个属性。\
>有多种方式可以创建，使用和修改 JavaScript 对象。\
>同样也有多种方式用来创建，使用和修改属性和方法。

## JavaScript 函数
>函数是由事件驱动的或者当它被调用时执行的可重复使用的代码块。
```js
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>测试实例</title>
<script>
function myFunction()
{
    alert("Hello World!");
}
</script>
</head>
 
<body>
<button onclick="myFunction()">点我</button>
</body>
</html>
```

### JavaScript 函数语法
>函数就是包裹在花括号中的代码块，前面使用了关键词 function：
```js
function functionname()
{
    // 执行代码
}
```
>当调用该函数时，会执行函数内的代码。\
>可以在某事件发生时直接调用函数（比如当用户点击按钮时），并且可由 JavaScript 在任何位置进行调用。\
><font color=red >JavaScript 对大小写敏感。关键词 function 必须是小写的，并且必须以与函数名称相同的大小写来调用函数。</font>

### 调用带参数的函数
>在调用函数时，您可以向其传递值，这些值被称为参数。\
>这些参数可以在函数中使用。\
>您可以发送任意多的参数，由逗号 (,) 分隔：
```js
myFunction(argument1,argument2)
```
>当您声明函数时，请把参数作为变量来声明：
```js
function myFunction(var1,var2)
{
代码
}
```
>变量和参数必须以一致的顺序出现。第一个变量就是第一个被传递的参数的给定的值，以此类推。
```js
<p>点击这个按钮，来调用带参数的函数。</p>
<button onclick="myFunction('Harry Potter','Wizard')">点击这里</button>
<script>
function myFunction(name,job){
    alert("Welcome " + name + ", the " + job);
}
</script>
```

### 带有返回值的函数
#### 语法
```js
function myFunction()
{
    var x=5;
    return x;
}
```

```js
document.getElementById("demo").innerHTML=myFunction();
```

### 全局 JavaScript 变量
>在函数外声明的变量是全局变量，网页上的所有脚本和函数都能访问它。

### JavaScript 变量的生存期
>JavaScript 变量的生命期从它们被声明的时间开始。\
>局部变量会在函数运行以后被删除。\
>全局变量会在页面关闭后被删除。

### 向未声明的 JavaScript 变量分配值
>如果您把值赋给尚未声明的变量，该变量将被自动作为 window 的一个属性。\
>这条语句：
```js
carname="Volvo";
```
>将声明 window 的一个属性 carname。\
>非严格模式下给未声明变量赋值创建的全局变量，是全局对象的可配置属性，可以删除。
```js
var var1 = 1; // 不可配置全局属性
var2 = 2; // 没有使用 var 声明，可配置全局属性

console.log(this.var1); // 1
console.log(window.var1); // 1

delete var1; // false 无法删除
console.log(var1); //1

delete var2; 
console.log(delete var2); // true
console.log(var2); // 已经删除 报错变量未定义
```

## JavaScript 作用域
### JavaScript 作用域
>在 JavaScript 中, 对象和函数同样也是变量。\
>在 JavaScript 中, 作用域为可访问变量，对象，函数的集合。\
>JavaScript 函数作用域: 作用域在函数内修改。

### JavaScript 局部作用域
>变量在函数内声明，变量为局部作用域。\
>局部变量：只能在函数内部访问。
```js
// 此处不能调用 carName 变量
function myFunction() {
    var carName = "Volvo";
    // 函数内可调用 carName 变量
}
```
>因为局部变量只作用于函数内，所以不同的函数可以使用相同名称的变量。\
>局部变量在函数开始执行时创建，函数执行完后局部变量会自动销毁。

### JavaScript 全局变量
>变量在函数外定义，即为全局变量。\
>全局变量有 全局作用域: 网页中所有脚本和函数均可使用。 
```js
var carName = " Volvo";
 
// 此处可调用 carName 变量
function myFunction() {
    // 函数内可调用 carName 变量
}
```
>如果变量在函数内没有声明（没有使用 var 关键字），该变量为全局变量。\
>以下实例中 carName 在函数内，但是为全局变量。
```js
// 此处可调用 carName 变量
 
function myFunction() {
    carName = "Volvo";
    // 此处可调用 carName 变量
}
```
### JavaScript 变量生命周期
>JavaScript 变量生命周期在它声明时初始化。\
>局部变量在函数执行完毕后销毁。\
>全局变量在页面关闭后销毁。

### 函数参数
>函数参数只在函数内起作用，是局部变量。

### HTML 中的全局变量
在 HTML 中, 全局变量是 window 对象: 所有数据变量都属于 window 对象。
```js
//此处可使用 window.carName
 
function myFunction() {
    carName = "Volvo";
}
```
><font color=red>全局变量，或者函数，可以覆盖 window 对象的变量或者函数。\
>局部变量，包括 window 对象可以覆盖全局变量和函数</font>。

## JavaScript 事件
>HTML 事件是发生在 HTML 元素上的事情。\
>当在 HTML 页面中使用 JavaScript 时， JavaScript 可以触发这些事件。
### HTML 事件
>HTML 事件可以是浏览器行为，也可以是用户行为。\
>以下是 HTML 事件的实例：
* HTML 页面完成加载
* HTML input 字段改变时
* HTML 按钮被点击

>HTML 元素中可以添加事件属性，使用 JavaScript 代码来添加 HTML 元素。\
>单引号:
```js
<some-HTML-element some-event='JavaScript 代码'>
```

>在以下实例中，按钮元素中添加了 onclick 属性 (并加上代码):
```js
<p id="demo">Time:</p>
<button onclick="getElementById('demo').innerHTML=Date()">现在的时间是?</button>
```

>使用 this.innerHTML:
```js
<button onclick="this.innerHTML=Date()">现在的时间是?</button>
```

><font color=red>JavaScript代码通常是几行代码。比较常见的是通过事件属性来调用：</font>
```js
<p>点击按钮执行 <em>displayDate()</em> 函数.</p>
<button onclick="displayDate()">点这里</button>
<script>
function displayDate(){
	document.getElementById("demo").innerHTML=Date();
}
</script>
<p id="demo"></p>
```

### 常见的HTML事件
>下面是一些常见的HTML事件的列表:

事件 | 描述
-|-
onchange | HTML 元素改变
onclick | 用户点击 HTML 元素
onmouseover | 用户在一个HTML元素上移动鼠标
onmouseout | 用户从一个HTML元素上移开鼠标
onkeydown | 用户按下键盘按键
onload | 浏览器已完成页面的加载

### JavaScript 可以做什么?
>事件可以用于处理表单验证，用户输入，用户行为及浏览器动作:
* 页面加载时触发事件
* 页面关闭时触发事件
* 用户点击按钮执行动作
* 验证用户输入内容的合法性
* 等等 ...

>可以使用多种方法来执行 JavaScript 事件代码：
* HTML 事件属性可以直接执行 JavaScript 代码
* HTML 事件属性可以调用 JavaScript 函数
* 你可以为 HTML 元素指定自己的事件处理程序
* 你可以阻止事件的发生。
* 等等 ..

## JavaScript 字符串
>JavaScript 字符串用于存储和处理文本。

### JavaScript 字符串
```js
var carname = "Volvo XC60";
var carname = 'Volvo XC60';
var character = carname[7];
```

你可以在字符串中使用引号，字符串中的引号不要与字符串的引号相同:
```js
var answer = "It's alright";
var answer = "He is called 'Johnny'";
var answer = 'He is called "Johnny"';
var x = 'It\'s alright';
var y = "He is called \"Johnny\"";
```

### 字符串长度
>可以使用内置属性 length 来计算字符串的长度：
```js
var txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
var sln = txt.length;
```

### 特殊字符
>下表中列举了在字符串中可以使用转义字符转义的特殊字符：
代码 | 输出
-|-
\' | 单引号
\" | 双引号
\\ | 反斜杠
\n | 换行
\r | 回车
\t | tab(制表符)
\b | 退格符
\f | 换页符

### 字符串可以是对象
>通常， JavaScript 字符串是原始值，可以使用字符创建： var firstName = "John"\
>但我们也可以使用 new 关键字将字符串定义为一个对象： var firstName = new String("John")
```js
var x = "John";
var y = new String("John");
typeof x // 返回 String
typeof y // 返回 Object
```
><font color=red>不要创建 String 对象。它会拖慢执行速度，并可能产生其他副作用：</font>
```js
var x = "John";             
var y = new String("John");
(x === y) // 结果为 false，因为 x 是字符串，y 是对象
```
><font color=red>=== 为绝对相等，即数据类型与值都必须相等。</font>

### 字符串属性和方法
>原始值字符串，如 "John", 没有属性和方法(因为他们不是对象)。\
>原始值可以使用 JavaScript 的属性和方法，因为 JavaScript 在执行方法和属性时可以把原始值当作对象。

### 字符串属性
属性 | 描述
-|-
constructor | 返回创建字符串属性的函数
length | 返回字符串的长度
prototype | 允许您向对象添加属性和方法

### 字符串方法
方法 | 描述
-|-
charAt() | 返回指定索引位置的字符
charCodeAt() | 返回指定索引位置字符的 Unicode 值
concat() | 连接两个或多个字符串，返回连接后的字符串
fromCharCode() | 将 Unicode 转换为字符串
indexOf() | 返回字符串中检索指定字符第一次出现的位置
lastIndexOf() | 返回字符串中检索指定字符最后一次出现的位置
localeCompare() | 用本地特定的顺序来比较两个字符串
match() | 找到一个或多个正则表达式的匹配
replace() | 替换与正则表达式匹配的子串
search() | 检索与正则表达式相匹配的值
slice() | 提取字符串的片断，并在新的字符串中返回被提取的部分
split() | 把字符串分割为子字符串数组
substr() | 从起始索引号提取字符串中指定数目的字符
substring() | 提取字符串中两个指定的索引号之间的字符
toLocaleLowerCase() | 根据主机的语言环境把字符串转换为小写，只有几种语言（如土耳其语）具有地方特有的大小写映射
toLocaleUpperCase() | 根据主机的语言环境把字符串转换为大写，只有几种语言（如土耳其语）具有地方特有的大小写映射
toLowerCase() | 把字符串转换为小写
toString() | 返回字符串对象值
toUpperCase() | 把字符串转换为大写
trim() | 移除字符串首尾空白
valueOf() | 返回某个字符串对象的原始值

## JavaScript 运算符

### JavaScript 算术运算符
运算符 | 描述 | 例子 | x 运算结果 | y 运算结果
-|-|-|-|-
+ | 加法 | x=y+2 | 7 | 5
- | 减法 | x=y-2 | 3 | 5
* | 乘法 | x=y*2 | 10 | 5
/ | 除法 | x=y/2 | 2.5 | 5
% | 取模（余数） | x=y%2 | 1 | 5
++ | 自增 | x=++y | 6 | 6
++ | 自增 | x=y++ | 5 | 6
-- | 自减 | x=--y | 4 | 4
-- | 自减 | x=y-- | 5 | 4

### JavaScript 赋值运算符
运算符 | 例子 | 等同于 | 运算结果
-|-|-|-
= | x=y | x=5
+= | x+=y | x=x+y | x=15
-= | x-=y | x=x-y | x=5
\*= | x*=y | x=x*y | x=50
/= | x/=y | x=x/y | x=2
%= | x%=y | x=x%y | x=0

### 用于字符串的 + 运算符
>\+ 运算符用于把文本值或字符串变量加起来（连接起来）。\
>如需把两个或多个字符串变量连接起来，请使用 + 运算符。

### 对字符串和数字进行加法运算
>两个数字相加，返回数字相加的和，如果数字与字符串相加，返回字符串，如下实例：
```js
x=5+5;
y="5"+5;
z="Hello"+5;
```
result
```js
10
55
Hello5
```


## JavaScript 比较 和 逻辑运算符

### 比较运算符
>x=5，下面的表格解释了比较运算符:

运算符 | 描述 | 比较 | 返回值
-|-|-|-
== | 等于 | x==8 | false
== | 等于 | x==5 | true
=== | 绝对等于（值和类型均相等） | x==="5" | false
=== |  绝对等于（值和类型均相等） | x===5 | true
!= | 不等于 | x!=8 | true
!== | 不绝对等于（值和类型有一个不相等，或两个都不相等） | x!=="5" | true
!== | 不绝对等于（值和类型有一个不相等，或两个都不相等） | x!==5 | false
\> | 大于 | x>8 | false
< | 小于 | x<8 | true
\>= | 大于或等于 | x>=8 | false
<= | 小于或等于 | x<=8 | true

### 逻辑运算符
>逻辑运算符用于测定变量或值之间的逻辑。\
>给定 x=6 以及 y=3，下表解释了逻辑运算符：

运算符 | 描述 | 例子
-|-|-
&& | and | (x < 10 && y > 1) 为 true
\|\| | or | (x==5 \|\| y==5) 为 false
! | not | !(x==y) 为 true

### 条件运算符
>JavaScript 还包含了基于某些条件对变量进行赋值的条件运算符。

```js
variablename=(condition)?value1:value2 
//eg.
voteable=(age<18)?"年龄太小":"年龄已达到";
```

## JavaScript if...Else 语句

### 条件语句
>在 JavaScript 中，我们可使用以下条件语句：
>- if 语句 - 只有当指定条件为 true 时，使用该语句来执行代码
>- if...else 语句 - 当条件为 true 时执行代码，当条件为 false 时执行其他代码
>- if...else if....else 语句- 使用该语句来选择多个代码块之一来执行
>- switch 语句 - 使用该语句来选择多个代码块之一来执行

### JavaScript switch 语句
```js
switch(n)
{
    case 1:
        执行代码块 1
        break;
    case 2:
        执行代码块 2
        break;
    default:
        与 case 1 和 case 2 不同时执行的代码
}
```
>工作原理：首先设置表达式 n（通常是一个变量）。随后表达式的值会与结构中的每个 case 的值做比较。如果存在匹配，则与该 case 关联的代码块会被执行。请使用 break 来阻止代码自动地向下一个 case 运行。
```js
var d=new Date().getDay(); 
switch (d) 
{ 
  case 0:x="今天是星期日"; 
  break; 
  case 1:x="今天是星期一"; 
  break; 
  case 2:x="今天是星期二"; 
  break; 
  case 3:x="今天是星期三"; 
  break; 
  case 4:x="今天是星期四"; 
  break; 
  case 5:x="今天是星期五"; 
  break; 
  case 6:x="今天是星期六"; 
  break; 
}
```

#### default 关键词
>请使用 default 关键词来规定匹配不存在时做的事情：
```js
var d=new Date().getDay();
switch (d)
{
    case 6:x="今天是星期六";
    break;
    case 0:x="今天是星期日";
    break;
    default:
    x="期待周末";
}
document.getElementById("demo").innerHTML=x;
```

## JavaScript for 循环

### JavaScript 循环
>eg.:
```js
for (var i=0;i<cars.length;i++)
{
    document.write(cars[i] + "<br>");
}
```

### 不同类型的循环
>JavaScript 支持不同类型的循环：

- for - 循环代码块一定的次数
- for/in - 循环遍历对象的属性
- while - 当指定的条件为 true 时循环指定的代码块
- do/while - 同样当指定的条件为 true 时循环指定的代码块

### For 循环
>for 循环是您在希望创建循环时常会用到的工具。
```js
for (语句 1; 语句 2; 语句 3)
{
    被执行的代码块
}
```
>eg.:
```js
for (var i=0; i<5; i++)
{
      x=x + "该数字为 " + i + "<br>";
}
```
#### 语句 1
>可以在语句 1 中初始化任意（或者多个）值：
```js
for (var i=0,len=cars.length; i<len; i++)
{
        document.write(cars[i] + "<br>");
}
```
>同时您还可以省略语句 1（比如在循环开始前已经设置了值时）：
```js
var i=2,len=cars.length;
for (; i<len; i++)
{
        document.write(cars[i] + "<br>");
}
```
#### 语句 2
>通常语句 2 用于评估初始变量的条件。\
>语句 2 同样是可选的。\
>如果语句 2 返回 true，则循环再次开始，如果返回 false，则循环将结束。
><font color=red>如果您省略了语句 2，那么必须在循环内提供 break。否则循环就无法停下来。这样有可能令浏览器崩溃。请在本教程稍后的章节阅读有关 break 的内容。</font>

#### 语句 3
>通常语句 3 会增加初始变量的值。\
>语句 3 也是可选的。\
>语句 3 有多种用法。增量可以是负数 (i--)，或者更大 (i=i+15)。\
>语句 3 也可以省略（比如当循环内部有相应的代码时）：
```js
var i=0,len=cars.length;
for (; i<len; )
{
        document.write(cars[i] + "<br>");
        i++;
}
```

### For/In 循环
>eg.:
```js
var person={fname:"John",lname:"Doe",age:25};
for (x in person)  // x 为属性名
{
    txt=txt + person[x];
}
```

### While 循环
>eg.:
```js
while (i<5)
{
        x=x + "The number is " + i + "<br>";
        i++;
}
```

### do/while 循环
>do/while 循环是 while 循环的变体。该循环会在检查条件是否为真之前执行一次代码块，然后如果条件为真的话，就会重复这个循环。
```js
do
{
        x=x + "The number is " + i + "<br>";
        i++;
}
while (i<5);
```
### 比较 for 和 while
>for eg.:
```js
cars=["BMW","Volvo","Saab","Ford"];
var i=0;
for (;cars[i];)
{
        document.write(cars[i] + "<br>");
        i++;
}
```
>while eg.:
```js
cars=["BMW","Volvo","Saab","Ford"];
var i=0;
while (cars[i])
{
        document.write(cars[i] + "<br>");
        i++;
}
```

### JavaScript Break 和 Continue 语句
>break 语句用于跳出循环。\
>continue 用于跳过循环中的一个迭代

#### Break 语句
```js
for (i=0;i<10;i++)
{
        if (i==3)
        {
                break;
        }
        x=x + "The number is " + i + "<br>";
}
```
#### Continue 语句
```js
for (i=0;i<=10;i++)
{
        if (i==3) continue;
        x=x + "The number is " + i + "<br>";
}
```

#### JavaScript 标签
>正如您在 switch 语句那一章中看到的，可以对 JavaScript 语句进行标记。\
>如需标记 JavaScript 语句，请在语句之前加上冒号：
```js
label:
statements
```
>break 和 continue 语句仅仅是能够跳出代码块的语句。\
>语法:
```js
break labelname;

continue labelname;
```
>continue 语句（带有或不带标签引用）只能用在循环中。\
>break 语句（不带标签引用），只能用在循环或 switch 中。\
>通过标签引用，break 语句可用于跳出任何 JavaScript 代码块：
```js
cars=["BMW","Volvo","Saab","Ford"];
list://标签
{
        document.write(cars[0] + "<br>");
        document.write(cars[1] + "<br>");
        document.write(cars[2] + "<br>");
        break list;
        document.write(cars[3] + "<br>");
        document.write(cars[4] + "<br>");
        document.write(cars[5] + "<br>");
}
```

## JavaScript typeof, null, 和 undefined

### typeof 操作符
>你可以使用 typeof 操作符来检测变量的数据类型。
```js
typeof "John"                // 返回 string
typeof 3.14                  // 返回 number
typeof false                 // 返回 boolean
typeof [1,2,3,4]             // 返回 object
typeof {name:'John', age:34} // 返回 object
```
><font color=orange>在JavaScript中，数组是一种特殊的对象类型。 因此 typeof [1,2,3,4] 返回 object。 </font>

### null
>在 JavaScript 中 null 表示 "什么都没有"。\
>null是一个只有一个值的特殊类型。表示一个空对象引用。\
><font color=red>用 typeof 检测 null 返回是object。</font>\
>可以设置为 null 来清空对象:
```js
var person = null;           // 值为 null(空), 但类型为对象
```
>可以设置为 undefined 来清空对象:
```js
var person = undefined;     // 值为 undefined, 类型为 undefined
```

### undefined
>在 JavaScript 中, undefined 是一个没有设置值的变量。\
>typeof 一个没有值的变量会返回 undefined。
```js
var person;                  // 值为 undefined(空), 类型是undefined
```
>任何变量都可以通过设置值为 undefined 来清空。 类型为 undefined.
```js
person = undefined;          // 值为 undefined, 类型是undefined
```

### undefined 和 null 的区别
>null 和 undefined 的值相等，但类型不等：
```js
typeof undefined             // undefined
typeof null                  // object
null === undefined           // false
null == undefined            // true
```

## JavaScript 类型转换

>Number() 转换为数字， String() 转换为字符串， Boolean() 转化为布尔值。

### JavaScript 数据类型
>在 JavaScript 中有 5 种不同的数据类型：
- string
- number
- boolean
- object
- function
>3 种对象类型：
- Object
- Date
- Array
>2 个不包含任何值的数据类型：
- null
- undefined

### typeof 操作符
>可以使用 typeof 操作符来查看 JavaScript 变量的数据类型。
```js
typeof "John"                 // 返回 string
typeof 3.14                   // 返回 number
typeof NaN                    // 返回 number
typeof false                  // 返回 boolean
typeof [1,2,3,4]              // 返回 object
typeof {name:'John', age:34}  // 返回 object
typeof new Date()             // 返回 object
typeof function () {}         // 返回 function
typeof myCar                  // 返回 undefined (如果 myCar 没有声明)
typeof null                   // 返回 object
```
>具体代码
```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
</head>
<body>

<p> typeof 操作符返回变量、对象、函数、表达式的类型。</p>
<p id="demo"></p>
<script>
document.getElementById("demo").innerHTML = 
    typeof "john" + "<br>" +
    typeof 3.14 + "<br>" +
    typeof NaN + "<br>" +
    typeof false + "<br>" +
    typeof [1,2,3,4] + "<br>" +
    typeof {name:'john', age:34} + "<br>" +
    typeof new Date() + "<br>" +
    typeof function () {} + "<br>" +
    typeof myCar + "<br>" +
    typeof null;
</script>

</body>
</html>
```
><font color=red> 请注意：</font>
- NaN 的数据类型是 number
- 数组(Array)的数据类型是 object
- 日期(Date)的数据类型为 object
- null 的数据类型是 object
- 未定义变量的数据类型为 undefined

><font color=red>如果对象是 JavaScript Array 或 JavaScript Date ，我们就无法通过 typeof 来判断他们的类型，因为都是 返回 object。</font>

### constructor 属性
>constructor 属性返回所有 JavaScript 变量的构造函数。
```js
"John".constructor                 // 返回函数 String()  { [native code] }
(3.14).constructor                 // 返回函数 Number()  { [native code] }
false.constructor                  // 返回函数 Boolean() { [native code] }
[1,2,3,4].constructor              // 返回函数 Array()   { [native code] }
{name:'John', age:34}.constructor  // 返回函数 Object()  { [native code] }
new Date().constructor             // 返回函数 Date()    { [native code] }
function () {}.constructor         // 返回函数 Function(){ [native code] }
```

>可以使用 constructor 属性来查看对象是否为数组 (包含字符串 "Array",即，constructor返回的字符串是否有Array):
```js
function isArray(myArray) {
    return myArray.constructor.toString().indexOf("Array") > -1;
}
```
>你可以使用 constructor 属性来查看对象是否为日期 (包含字符串 "Date"):
```js
function isDate(myDate) {
    return myDate.constructor.toString().indexOf("Date") > -1;
}
```
### JavaScript 类型转换
>JavaScript 变量可以转换为新变量或其他数据类型：
- 通过使用 JavaScript 函数
- 通过 JavaScript 自身自动转换
#### 将数字转换为字符串
>全局方法 String() 可以将数字转换为字符串。\
>该方法可用于任何类型的数字，字母，变量，表达式：
```js
String(x)         // 将变量 x 转换为字符串并返回
String(123)       // 将数字 123 转换为字符串并返回
String(100 + 23)  // 将数字表达式转换为字符串并返回
```
>Number 方法 toString() 也是有同样的效果。
```js
x.toString()
(123).toString()
(100 + 23).toString()
```
方法 | 描述
-|-
toExponential() | 把对象的值转换为指数计数法。
toFixed() | 把数字转换为字符串，结果的小数点后有指定位数的数字。
toPrecision() | 把数字格式化为指定的长度。

#### 将布尔值转换为字符串
>全局方法 String() 可以将布尔值转换为字符串。
```js
String(false)        // 返回 "false"
String(true)         // 返回 "true"
```
#### 将日期转换为字符串
>Date() 返回字符串。
```js
Date()      // 返回 Thu Jul 17 2014 15:38:19 GMT+0200 (W. Europe Daylight Time)
```
>全局方法 String() 可以将日期对象转换为字符串。
```js
String(new Date())      // 返回 Thu Jul 17 2014 15:38:19 GMT+0200 (W. Europe Daylight Time)
```
>Date 方法 toString() 也有相同的效果。
```js
obj = new Date()
obj.toString()   // 返回 Thu Jul 17 2014 15:38:19 GMT+0200 (W. Europe Daylight Time)
```
方法 | 描述
-|-
getDate() | 从 Date 对象返回一个月中的某一天 (1 ~ 31)。
getDay() | 从 Date 对象返回一周中的某一天 (0 ~ 6)。
getFullYear() | 从 Date 对象以四位数字返回年份。
getHours() | 返回 Date 对象的小时 (0 ~ 23)。
getMilliseconds() | 返回 Date 对象的毫秒(0 ~ 999)。
getMinutes() | 返回 Date 对象的分钟 (0 ~ 59)。
getMonth() | 从 Date 对象返回月份 (0 ~ 11)。
getSeconds() | 返回 Date 对象的秒数 (0 ~ 59)。
getTime() | 返回 1970 年 1 月 1 日至今的毫秒数。

### 将字符串转换为数字
>全局方法 Number() 可以将字符串转换为数字。\
>字符串包含数字(如 "3.14") 转换为数字 (如 3.14).\
>空字符串转换为 0。\
>其他的字符串会转换为 NaN (不是个数字)。

```js
Number("3.14")    // 返回 3.14
Number(" ")       // 返回 0
Number("")        // 返回 0
Number("99 88")   // 返回 NaN
```

方法 | 描述
-|-
parseFloat() | 解析一个字符串，并返回一个浮点数。
parseInt() | 解析一个字符串，并返回一个整数。

### 一元运算符 +
>Operator + 可用于将变量转换为数字：
```js
var y = "5";      // y 是一个字符串
var x = + y;      // x 是一个数字
```
>如果变量不能转换，它仍然会是一个数字，但值为 NaN (不是一个数字):
```js
var y = "John";   // y 是一个字符串
var x = + y;      // x 是一个数字 (NaN)
```

### 将布尔值转换为数字
>全局方法 Number() 可将布尔值转换为数字。
```js
Number(false)     // 返回 0
Number(true)      // 返回 1
```
### 将日期转换为数字
>全局方法 Number() 可将日期转换为数字。
```js
d = new Date();
Number(d)          // 返回 1404568027739
```
>日期方法 getTime() 也有相同的效果。
```js
d = new Date();
d.getTime()        // 返回 1404568027739
```

### 自动转换类型
>当 JavaScript 尝试操作一个 "错误" 的数据类型时，会自动转换为 "正确" 的数据类型。\
>以下输出结果不是你所期望的
```js
5 + null    // 返回 5         null 转换为 0
"5" + null  // 返回"5null"   null 转换为 "null"
"5" + 1     // 返回 "51"      1 转换为 "1" 
"5" - 1     // 返回 4         "5" 转换为 5
```
>注意：<font color=red>"5" - 1     // 返回 4         "5" 转换为 5</font>


### 自动转换为字符串
>当你尝试输出一个对象或一个变量时 JavaScript 会自动调用变量的 toString() 方法：
```js
document.getElementById("demo").innerHTML = myVar;

myVar = {name:"Fjohn"}  // toString 转换为 "[object Object]"
myVar = [1,2,3,4]       // toString 转换为 "1,2,3,4"
myVar = new Date()      // toString 转换为 "Fri Jul 18 2014 09:08:55 GMT+0200"
```
>数字和布尔值也经常相互转换：
```js
myVar = 123             // toString 转换为 "123"
myVar = true            // toString 转换为 "true"
myVar = false           // toString 转换为 "false"
```
>下表展示了使用不同的数值转换为数字(Number), 字符串(String), 布尔值(Boolean):

原始值 | 转换为数字 | 转换为字符串 | 转换为布尔值
-|-|-|-
false | 0 | "false" | false
true | 1 | "true" | true
0 | 0 | "0" | false
1 | 1 | "1" | true
"0" | 0 | "0" | true
"000" | 0 | "000" | true
"1" | 1 | "1 | true
NaN | NaN | "NaN" | false
Infinity | Infinity | "Infinity" | true
-Infinity | -Infinity | "-Infinity" | true
"" | 0 | "" | false
"20" | 20 | "20" | true
"Runoob" | NaN | "Runoob" | true
[ ] | 0 | "" | true
[20] | 20 | "20" | true
[10,20] | NaN | "10,20" | true
["Runoob"] | NaN | "Runoob" | true
["Runoob","Google"] | NaN | "Runoob,Google" | true
function(){} | NaN | "function(){}" | true
{ } | NaN | "[object Object]" | true
null | 0 | "null" | false
undefined | NaN | "undefined" | false

## JavaScript 正则表达式
>正则表达式（英语：Regular Expression，在代码中常简写为regex、regexp或RE）使用单个字符串来描述、匹配一系列符合某个句法规则的字符串搜索模式。\
>搜索模式可用于文本搜索和文本替换。

### 什么是正则表达式？
>正则表达式是由一个字符序列形成的搜索模式。\
>当你在文本中搜索数据时，你可以用搜索模式来描述你要查询的内容。\
>正则表达式可以是一个简单的字符，或一个更复杂的模式。\
>正则表达式可用于所有文本搜索和文本替换的操作。

### 语法
```js
/正则表达式主体/修饰符(可选)
```
>其中修饰符是可选的。
```js
var patt = /runoob/i
```
>实例解析：\
>**/runoob/i**  是一个正则表达式。\
>**runoob**  是一个正则表达式主体 (用于检索)。\
>**i**  是一个修饰符 (搜索不区分大小写)。

### 使用字符串方法
>在 JavaScript 中，正则表达式通常用于两个字符串方法 : search() 和 replace()。\
>**search()** 方法 用于检索字符串中指定的子字符串，或检索与正则表达式相匹配的子字符串，并返回子串的起始位置。\
>**replace()** 方法 用于在字符串中用一些字符替换另一些字符，或替换一个与正则表达式匹配的子串。

### search() 方法使用正则表达式
```js
//使用正则表达式搜索 "Runoob" 字符串，且不区分大小写：
var str = "Visit Runoob!";
var n = str.search(/Runoob/i);

//result 6
```

### **search()** 方法使用字符串
>**search** 方法可使用字符串作为参数。字符串参数会转换为正则表达式：
```js
//检索字符串中 "Runoob" 的子串：
var str = "Visit Runoob!";
var n = str.search("Runoob");
```
### **replace()** 方法使用正则表达式
```js
//使用正则表达式且不区分大小写将字符串中的 Microsoft 替换为 Runoob :

<button onclick="myFunction()">点我</button>
<p id="demo">Visit Microsoft!</p>
<script>
function myFunction() {
    var str = document.getElementById("demo").innerHTML; 
    var txt = str.replace(/microsoft/i,"Runoob");
    document.getElementById("demo").innerHTML = txt;
}
</script>
```
### **replace()** 方法使用字符串
>replace() 方法将接收字符串作为参数：
```js
var str = document.getElementById("demo").innerHTML;
var txt = str.replace("Microsoft","Runoob");
```
><font color=red>正则表达式参数可用在以上方法中 (替代字符串参数)。\
>正则表达式使得搜索功能更加强大(如实例中不区分大小写)。</font>

### 正则表达式修饰符
>修饰符 可以在全局搜索中不区分大小写:

修饰符 | 描述
-|-
i | 执行对大小写不敏感的匹配。
g | 执行全局匹配（查找所有匹配而非在找到第一个匹配后停止）。
m | 执行多行匹配。

### 正则表达式模式
>方括号用于查找某个范围内的字符：

表达式 | 描述
-|-
[abc] | 查找方括号之间的任何字符。
[0-9] | 查找任何从 0 至 9 的数字。
(x\|y) | 查找任何以 \| 分隔的选项。

>元字符是拥有特殊含义的字符：

元字符 | 描述
-|-
\d | 查找数字。
\s | 查找空白字符。
\b | 匹配单词边界。
\uxxxx | 查找以十六进制数 xxxx 规定的 Unicode 字符。

>量词:

量词 | 描述
-|-
n+ | 匹配任何包含至少一个 n 的字符串。
n* | 匹配任何包含零个或多个 n 的字符串。
n? | 匹配任何包含零个或一个 n 的字符串。

### 使用 **RegExp** 对象
><font color=red>在 JavaScript 中，**RegExp** 对象是一个预定义了属性和方法的正则表达式对象。</font>

### 使用 **test()**
>test() 方法是一个正则表达式方法。\
>test() 方法用于检测一个字符串是否匹配某个模式，如果字符串中含有匹配的文本，则返回 true，否则返回 false。\
>以下实例用于搜索字符串中的字符 "e"：
```js
<script>
var patt1=new RegExp("e");
document.write(patt1.test("The best things in life are free"));
</script>
```
```js
//你可以不用设置正则表达式的变量，以上两行代码可以合并为一行：
/e/.test("The best things in life are free!")
```
### 使用 **exec()**
>**exec()** 方法是一个正则表达式方法。\
>**exec()** 方法用于检索字符串中的正则表达式的匹配。\
>该函数返回一个数组，其中存放匹配的结果。如果未找到匹配，则返回值为 null。\
>以下实例用于搜索字符串中的字母 "e":
```js
<script>
var patt1=new RegExp("e");
document.write(patt1.exec("The best things in life are free"));
</script>
```

## JavaScript 错误 - **throw、try 和 catch**
>try 语句测试代码块的错误。\
>catch 语句处理错误。\
>throw 语句创建自定义错误。\
>finally 语句在 try 和 catch 语句之后，无论是否有触发异常，该语句都会执行。

### JavaScript 错误
>当 JavaScript 引擎执行 JavaScript 代码时，会发生各种错误。\
>可能是语法错误，通常是程序员造成的编码错误或错别字。\
>可能是拼写错误或语言中缺少的功能（可能由于浏览器差异）。\
>可能是由于来自服务器或用户的错误输出而导致的错误。\
>当然，也可能是由于许多其他不可预知的因素。

### JavaScript 抛出（throw）错误
>当错误发生时，当事情出问题时，JavaScript 引擎通常会停止，并生成一个错误消息。\
>描述这种情况的技术术语是：JavaScript 将**抛出**一个错误。

### JavaScript **try 和 catch**
>**try** 语句允许我们定义在执行时进行错误测试的代码块。\
>**catch** 语句允许我们定义当 try 代码块发生错误时，所执行的代码块。\
>JavaScript 语句 **try 和 catch** 是成对出现的。

#### 语法
```js
try {
    ...    //异常的抛出
} catch(e) {
    ...    //异常的捕获与处理
} finally {
    ...    //结束处理
}
```
### 实例
>在下面的例子中，我们故意在 try 块的代码中写了一个错字。\
>catch 块会捕捉到 try 块中的错误，并执行代码来处理它。
```js
<script>
var txt="";
function message(){
	try {
		adddlert("Welcome guest!");//addalert
	}
	catch(err) {
		txt="本页有一个错误。\n\n";
		txt+="错误描述：" + err.message + "\n\n";
		txt+="点击确定继续。\n\n";
		alert(txt);
	}
}
</script>
</head>
<body>

<input type="button" value="查看消息" onclick="message()" />
```
### finally 语句
>finally 语句不论之前的 try 和 catch 中是否产生异常都会执行该代码块。
```js
<p>不管输入是否正确，输入框都会再输入后清空。</p>
<p>请输入 5 ~ 10 之间的数字：</p>

<input id="demo" type="text">
<button type="button" onclick="myFunction()">点我</button>

<p id="p01"></p>

<script>
function myFunction() {
  var message, x;
  message = document.getElementById("p01");
  message.innerHTML = "";
  x = document.getElementById("demo").value;
  try { 
    if(x == "") throw "值是空的";
    if(isNaN(x)) throw "值不是一个数字";
    x = Number(x);
    if(x > 10) throw "太大";
    if(x < 5) throw "太小";
  }
  catch(err) {
    message.innerHTML = "错误: " + err + ".";
  }
  finally {
    document.getElementById("demo").value = "";
  }
}
</script>
```
### **Throw** 语句
>**throw** 语句允许我们创建自定义错误。\
>正确的技术术语是：创建或**抛出异常**（exception）。\
>如果把 throw 与 try 和 catch 一起使用，那么您能够控制程序流，并生成自定义的错误消息。
#### 语法
>throw exception \
>异常可以是 JavaScript 字符串、数字、逻辑值或对象。

### 实例
>本例检测输入变量的值。如果值是错误的，会抛出一个异常（错误）。
>catch 会捕捉到这个错误，并显示一段自定义的错误消息：
```js
function myFunction() {
    var message, x;
    message = document.getElementById("message");
    message.innerHTML = "";
    x = document.getElementById("demo").value;
    try {
        if(x == "")  throw "值为空";
        if(isNaN(x)) throw "不是数字";
        x = Number(x);
        if(x < 5)    throw "太小";
        if(x > 10)   throw "太大";
    }
    catch(err) {
        message.innerHTML = "错误: " + err;
    }
}
```
>请注意，如果 getElementById 函数出错，上面的例子也会抛出一个错误。

## JavaScript 调试
### JavaScript 调试工具
>在程序代码中寻找错误叫做代码调试。\
>调试很难，但幸运的是，很多浏览器都内置了调试工具。\
>内置的调试工具可以开始或关闭，严重的错误信息会发送给用户。\
>有了调试工具，我们就可以设置断点 (代码停止执行的位置), 且可以在代码执行时检测变量。\
>浏览器启用调试工具一般是按下 F12 键，并在调试菜单中选择 "Console" 。

### console.log() 方法
>如果浏览器支持调试，你可以使用 console.log() 方法在调试窗口上打印 JavaScript 值：
```js
<p>
浏览器中(Chrome, IE, Firefox) 使用 F12 来启用调试模式， 在调试窗口中点击 "Console" 菜单。
</p>
<script>
a = 5;
b = 6;
c = a + b;
console.log(c);
</script>
```

### 设置断点
>在调试窗口中，你可以设置 JavaScript 代码的断点。\
>在每个断点上，都会停止执行 JavaScript 代码，以便于我们检查 JavaScript 变量的值。\
>在检查完毕后，可以重新执行代码（如播放按钮）。

### debugger 关键字
>debugger 关键字用于停止执行 JavaScript，并调用调试函数。\
>这个关键字与在调试工具中设置断点的效果是一样的。\
>如果没有调试可用，debugger 语句将无法工作。\
>开启 debugger ，代码在第三行前停止执行。
```js
<p id="demo"></p>
<p>开启调试工具，在代码执行到第三行前会停止执行。</p>
<script>
var x = 15 * 5;
debugger;
document.getElementById("demo").innerHTML = x;
</script>
```

## JavaScript 变量提升
><font color=red>JavaScript 中，函数及变量的***声明***都将被提升到函数的最顶部。\
>JavaScript 中，变量可以在使用后声明，也就是变量可以先使用再声明。</font>\
>以下两个实例将获得相同的结果：
```js
<p id="demo"></p>
<script>
x = 5; // 变量 x 设置为 5
elem = document.getElementById("demo"); // 查找元素 
elem.innerHTML = x;                     // 在元素中显示 x
var x; // 声明 x
</script>
```
>eg.2:
```js
<p id="demo"></p>
<script>
var x; // 声明 x
x = 5; // 变量 x 设置为 5
elem = document.getElementById("demo"); // 查找元素 
elem.innerHTML = x; 
</script>
```

>要理解以上实例就需要理解 "hoisting(变量提升)"。
>变量提升：函数声明和变量声明总是会被解释器悄悄地被"提升"到方法体的最顶部。

### JavaScript 初始化不会提升
>JavaScript 只有声明的变量会提升，初始化的不会。\
>以下两个实例结果结果不相同：
```js
<p id="demo"></p>
<script>
var x = 5; // 初始化 x
var y = 7; // 初始化 y
elem = document.getElementById("demo"); // 查找元素 
elem.innerHTML = x + " " + y;           // 显示 x 和 y
</script>
```
eg.2
```js
<p id="demo"></p>
<script>
var x = 5; // 初始化 x
elem = document.getElementById("demo"); // 查找元素 
elem.innerHTML = "x 为：" + x + "，y 为：" + y;           // 显示 x 和 y
var y = 7; // 初始化 y
</script>
```
>实例 2 的 y 输出了 undefined，这是因为变量声明 (var y) 提升了，但是初始化(y = 7) 并不会提升，所以 y 变量是一个未定义的变量。\
>实例 2 类似以下代码:
```js
var x = 5; // 初始化 x
var y;     // 声明 y

elem = document.getElementById("demo"); // 查找元素
elem.innerHTML = x + " " + y;           // 显示 x 和 y

y = 7;    // 设置 y 为 7
```

### 在头部声明你的变量
>对于大多数程序员来说并不知道 JavaScript 变量提升。\
>如果程序员不能很好的理解变量提升，他们写的程序就容易出现一些问题。\
>为了避免这些问题，通常我们在每个作用域开始前声明这些变量，这也是正常的 JavaScript 解析步骤，易于我们理解。

><font color=red>JavaScript 严格模式(strict mode)不允许使用未声明的变量。
>在下一个章节中我们将会学习到 "严格模式(strict mode)" 。</font>

## JavaScript 严格模式(use strict)
>JavaScript 严格模式（strict mode）即在严格的条件下运行。
### 使用 "use strict" 指令
>"use strict" 指令在 JavaScript 1.8.5 (ECMAScript5) 中新增。\
>它不是一条语句，但是是一个字面量表达式，在 JavaScript 旧版本中会被忽略。\
>"use strict" 的目的是指定代码在严格条件下执行。\
>严格模式下你不能使用未声明的变量。

### 严格模式声明
>严格模式通过在脚本或函数的头部添加 "use strict"; 表达式来声明。\
>实例中我们可以在浏览器按下 F12 (或点击"工具>更多工具>开发者工具") 开启调试模式，查看报错信息。
```js
<h1>使用 "use strict":</h1>
<h3>不允许使用未定义的变量。</h3>
<p>浏览器按下 F12 开启调试模式，查看报错信息。</p>
<script>
"use strict";
x = 3.14;       // 报错 (x 未定义)
</script>
```
eg.2:
```js
<h2>全局 "use strict" 声明.</h2>
<p>浏览器按下 F12 开启调试模式，查看报错信息。</p>
<script>
"use strict";
myFunction();
function myFunction() {
    y = 3.14;   // 报错 (y 未定义)
}
</script>
```
><font color=orange>在函数内部声明是局部作用域 (只在函数内使用严格模式):</font>
```js
<p>在函数内使用 "use strict" 只在函数内报错。
</p>
<p>浏览器按下 F12 开启调试模式，查看报错信息。</p>
<script>
x = 3.14;       // 不报错 
myFunction();
function myFunction() {
   "use strict";
    y = 3.14;   // 报错 (y 未定义)
}
</script>
```
>为什么使用严格模式:\
>消除Javascript语法的一些不合理、不严谨之处，减少一些怪异行为;\
>消除代码运行的一些不安全之处，保证代码运行的安全；\
>提高编译器效率，增加运行速度；\
>为未来新版本的Javascript做好铺垫。\
>"严格模式"体现了Javascript更合理、更安全、更严谨的发展方向，包括IE 10在内的主流浏览器，都已经支持它，许多大项目已>经开始全面拥抱它。\
>
>另一方面，同样的代码，在"严格模式"中，可能会有不一样的运行结果；一些在"正常模式"下可以运行的语句，在"严格模式"下将>不能运行。掌握这些内容，有助于更细致深入地理解Javascript，让你变成一个更好的程序员。\

### 严格模式的限制
>不允许使用未声明的变量：
```js
<h1>使用 "use strict":</h1>
<h3>不允许使用未定义的变量。</h3>
<p>浏览器按下 F12 开启调试模式，查看报错信息。</p>
<script>
"use strict";
x = 3.14;       // 报错 (x 未定义)
</script>
```
><font color=red>对象也是一个变量。</font>
>eg.2:
```js
<h1>使用 "use strict":</h1>
<h3>不允许使用未定义的对象。</h3>
<p>浏览器按下 F12 开启调试模式，查看报错信息。</p>
<script>
"use strict";
x = {p1:10, p2:20};      // 报错 (x 未定义)
</script>
```
>不允许删除变量或对象。eg.3:
```js
<h1>使用 "use strict":</h1>
<h3>不允许删除变量或对象。</h3>
<p>浏览器按下 F12 开启调试模式，查看报错信息。</p>
<script>
"use strict";
var x = 3.14;
delete x;    
</script>
```
>不允许删除函数。eg.4:
```js
<script>
"use strict";
function x(p1, p2) {}; 
delete x;  
</script>
```
>不允许变量重名:eg.5:
```js
"use strict";
function x(p1, p1) {};   // 报错
```
>不允许使用八进制:eg.6:
```js
"use strict";
var x = 010;             // 报错
```
>不允许使用转义字符:eg.7:
```js
"use strict";
var x = \010;            // 报错
```
>不允许对只读属性赋值:eg.8:
```js
"use strict";
var obj = {};
Object.defineProperty(obj, "x", {value:0, writable:false});

obj.x = 3.14;            // 报错
```
>不允许对一个使用getter方法读取的属性进行赋值,eg.9:
```js
"use strict";
var obj = {get x() {return 0} };

obj.x = 3.14;            // 报错

```
>不允许删除一个不允许删除的属性,eg.10:
```js
"use strict";
delete Object.prototype; // 报错`
```
>变量名不能使用 "eval" 字符串,eg.11:
```js
"use strict";
var eval = 3.14;         // 报错
```
>变量名不能使用 "arguments" 字符串,eg.12:
```js
"use strict";
var arguments = 3.14;    // 报错
```
>不允许使用以下这种语句,eg.13:
```js
"use strict";
with (Math){x = cos(2)}; // 报错
```
>由于一些安全原因，在作用域 eval() 创建的变量不能被调用,eg.14:
```js
"use strict";
eval ("var x = 2");
alert (x);               // 报错
```
>禁止this关键字指向全局对象,eg.15:
```js
function f(){
    return !this;
} 
// 返回false，因为"this"指向全局对象，"!this"就是false

function f(){ 
    "use strict";
    return !this;
} 
// 返回true，因为严格模式下，this的值为undefined，所以"!this"为true。
```
>因此，使用构造函数时，如果忘了加new，this不再指向全局对象，而是报错,eg.16:
```js
function f(){
    "use strict";
    this.a = 1;
};
f();// 报错，this未定义
```
### 保留关键字:
>为了向将来Javascript的新版本过渡，严格模式新增了一些保留关键字：
- implements
- interface
- let
- package
- private
- protected
- public
- static
- yield
eg.:
```js
"use strict";
var public = 1500;      // 报错
```
><font color=red>	"use strict" 指令只允许出现在脚本或函数的开头。</font>

