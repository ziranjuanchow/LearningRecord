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
