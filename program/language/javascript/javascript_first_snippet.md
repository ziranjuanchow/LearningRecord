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
