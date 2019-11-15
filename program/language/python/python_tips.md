## 1. py to pyd
a.安装cython
````
pip install Cython --install-option="--no-cython-compile"
````
b.测试文件 a.py
````
def test():
    print "Hello World!"
````
c.创建setup.py文件
````
from distutils.core import setup
from Cython.Build import cythonize
setup(name = 'Hello world',
      ext_modules = cythonize("a.py"))
````
d.生成pyd
````
python setup.py build_ext --inplace
````
e.处理vcvarsall.bat
````http://aka.ms/vcpython27```` 下载

修改
````
C:\Users\Administrator\AppData\Local\Programs\Common\Microsoft\Visual C++ for Python\9.0\vcvarsall.bat
````
````
def get_build_version():
    """Return the version of MSVC that was used to build Python.
 
    For Python 2.3 and up, the version number is included in
    sys.version.  For earlier versions, assume the compiler is MSVC 6.
    """
    return 9.0
````
以及
````
def find_vcvarsall(version):
    """Find the vcvarsall.bat file
 
    At first it tries to find the productdir of VS 2008 in the registry. If
    that fails it falls back to the VS90COMNTOOLS env var.
    """
    return r'C:\Users\Administrator\AppData\Local\Programs\Common\Microsoft\Visual C++ for Python\9.0\vcvarsall.bat'
    vsbase = VS_BASE % version
````

## 2. self / cls
````
Function and method arguments:
Always use self for the first argument to instance methods.
Always use cls for the first argument to class methods.
````
>&nbsp;&nbsp;self表示一个具体的实例本身。如果用了staticmethod，那么就可以无视这个self，将这个方法当成一个普通的函数使用。<br>
>&nbsp;&nbsp;cls表示这个类本身。<br>
>&nbsp;&nbsp;类先调用__new__方法，返回该类的实例对象，这个实例对象就是__init__方法的第一个参数self，即self是__new__的返回值。<br>

>#### 特殊成员和魔法方法<br>
>http://www.liujiangblog.com/course/python/47<br>
>&nbsp;&nbsp;&nbsp;&nbsp;Python中有大量类似__doc__这种以双下划线开头和结尾的特殊成员及“魔法方法”，它们有着非常重要的地位和作用，也是Python语言独具特色的语法之一！<br>
>比如：
>````
>__doc__ :       说明性文档和信息。Python自建，无需自定义。
>__init__ :      构造函数，在生成对象时调用.实例化方法，通过类创建实例时，自动触发执行。
>__del__ :       析构函数，释放对象时使用。当对象在内存中被释放时，自动触发此方法。
>                    注：此方法一般无须自定义，因为Python自带内存分配和释放机制，除非你需要在释放的时候指定做一些动作。
>                    析构函数的调用是由解释器在进行垃圾回收时自动触发执行的。
>__module__ :    表示当前操作的对象在属于哪个模块。Python自建，无需自定义。
>__class__ ：    表示当前操作的对象属于哪个类。Python自建，无需自定义。
> __call__ :     如果为一个类编写了该方法，那么在该类的实例后面加括号，可会调用这个方法。
>                    注：构造方法的执行是由类加括号执行的，即：对象 = 类名()，而对于__call__() 方法，是由对象后加括号触发的，即：对象() 或者 类()()。
>                    callable(Student()) 判断Student()对象是否能被执行；
>__dict__ :      列出类或对象中的所有成员！非常重要和有用的一个属性，Python自建，无需用户自己定义。
>__str__ :       如果一个类中定义了__str__()方法，那么在打印对象时，默认输出该方法的返回值。这也是一个非常重要的方法，需要用户自己定义。
>__repr__ :      打印，转换;是为调试服务的。
>__setitem__ :   按照索引赋值;标识符[] = a:执行__setitem__方法
>__getitem__ :   按照索引获取值;a=标识符[]：执行__getitem__方法
>__delitem__ :   按照索引删除值;del 标识符[]:执行__delitem__方法
>__iter__ :      这是迭代器方法！列表、字典、元组之所以可以进行for循环，是因为其内部定义了 __iter__()这个方法。
>                 如果用户想让自定义的类的对象可以被迭代，那么就需要在类中定义这个方法，并且让该方法的返回值是一个可迭代的对象。
>                 当在代码中利用for循环遍历对象时，就会调用类的这个__iter__()方法。
>__len__ :       获得长度
>__cmp__ :       比较运算
>__call__ :      调用
>__add__ :       加运算
>__sub__ :       减运算
>__mul__ :       乘运算
>__div__ :       除运算
>__mod__ :       求余运算
>__pow__ :       幂
>__author__ ：   代表作者信息
>__slots__ :     __slots__限制实例的变量
>````

>__iter__():<br>
>返回一个个迭代对象：
````
class Foo:
    def __init__(self, sq):
        self.sq = sq

    def __iter__(self):
        return iter(self.sq)

obj = Foo([11,22,33,44])

for i in obj:
    print(i)
````
>最好的方法是使用生成器：
````
class Foo:
    def __init__(self):
        pass

    def __iter__(self):
        yield 1
        yield 2
        yield 3

obj = Foo()
for i in obj:
    print(i)
````
>__slots__<br>
>Python作为一种动态语言，可以在类定义完成和实例化后，给类或者对象继续添加随意个数或者任意类型的变量或方法，这是动态语言的特性。例如：
````
def print_doc(self):
    print("haha")

class Foo:
    pass

obj1 = Foo()
obj2 = Foo()
# 动态添加实例变量
obj1.name = "jack"
obj2.age = 18
# 动态的给类添加实例方法
Foo.show = print_doc
obj1.show()
obj2.show()
````
>但是！如果我想限制实例可以添加的变量怎么办？可以使__slots__限制实例的变量，比如，只允许Foo的实例添加name和age属性。
````
def print_doc(self):
    print("haha")

class Foo:
    __slots__ = ("name", "age")
    pass


obj1 = Foo()
obj2 = Foo()
# 动态添加实例变量
obj1.name = "jack"
obj2.age = 18
obj1.sex = "male"       # 这一句会弹出错误
# 但是无法限制给类添加方法
Foo.show = print_doc
obj1.show()
obj2.show()
````
>由于'sex'不在__slots__的列表中，所以不能绑定sex属性，试图绑定sex将得到AttributeError的错误。
````
Traceback (most recent call last):
  File "F:/Python/pycharm/201705/1.py", line 14, in <module>
    obj1.sex = "male"
AttributeError: 'Foo' object has no attribute 'sex'
````
>需要提醒的是，__slots__定义的属性仅对当前类的实例起作用，对继承了它的子类是不起作用的。想想也是这个道理，如果你继承一个父类，却莫名其妙发现有些变量无法定义，那不是大问题么？如果非要子类也被限制，除非在子类中也定义__slots__，这样，子类实例允许定义的属性就是自身的__slots__加上父类的__slots__。

## 3. reflect反射
>在前面的章节，我们遗留了hasattr()、getattr()、setattr()和delattr()的相关内容，它们在这里。<br>
对编程语言比较熟悉的同学，应该听说过“反射”这个机制。Python作为一门动态语言，当然不会缺少这一重要功能。下面结合一个web路由的实例来阐述Python反射机制的使用场景和核心本质。

## 4. 判断平台
`````
import platform
 
osName = platform.system()
if(osName == 'Windows'):
    import windowsEngine as engine
elif(osName == 'Linux'):
    import linuxEngine as engine
elif(osName == 'Darwin'):
    import macEngine as engine
    
         
if __name__ == "__main__": 
    print(platform.system())
`````

## 5. time and string
string to time
`````
datetime.strptime(date_string, format)
`````
time to string
`````
time.strptime(time_string[, format])
`````

## 6. pickle、cPickle包


## 7. 计算
pyhton2上是向下取整，python3是正确的了。比如-53/10，py2结果是-6，c/cpp是-5。这点是刷LeetCode的时候发现的，之前没注意~

## 8. 执行命令行
```
os.system(cmd)
os.popen(command[, mode[, bufsize]])
subprocess.Popen()
```


## 9. for in 前有参数情况
eg:
```python
ls2 = [str(i) for i in ls1]
```
等价于：
```python
ls2 = list()
for i in ls1:
    ls2.append(str(i))
```

## 10. 调用REST API的集中方式
- urllib2
- httplib2
- pycurl
- requests
  
### 1. urllib2
>Sample1
>```python
>import urllib2, urllib
>github_url = 'https://api.github.com/user/repos'
>password_manager = urllib2.HTTPPasswordMgrWithDefaultRealm()
>password_manager.add_password(None, github_url, 'user', '***')
>auth = urllib2.HTTPBasicAuthHandler(password_manager) # create an >authentication handler
>opener = urllib2.build_opener(auth) # create an opener with the >authentication handler
>urllib2.install_opener(opener) # install the opener... 
>request = urllib2.Request(github_url, urllib.urlencode({'name':'Test >repo', 'description': 'Some test repository'})) # Manual encoding required
>handler = urllib2.urlopen(request)
>print handler.read()
>```

>Sample2
>```python
>import urllib2
>url = 'http://ems.vip.ebay.com/removeSIforcloud.cgi?ip=' + ip
>req = urllib2.Request(url)
>req.add_header('IAF',abc.token_authiaas)
>try:
>    resp = urllib2.urlopen(req)
>except urllib2.HTTPError, error:
>    print "Cannot remove service instance!", error
>    sys.exit(1)
>response = resp.read()
>print response
>```

>Sample3
>```python
>import urllib2, urllib, base64
>url = "https://reparo.stratus.ebay.com/reparo/bootstrap/registerasset/" + >rackid + "/" + asset
>data = urllib.urlencode({
>                'reservedResource':'RR-Hadoop',
>                'resourceCapability':'Production',
>                'movetoironic':'False',
>                'output':'json'
>        })
>print "Bootstrap Asset jobs starting .............."
>base64string = base64.encodestring('%s:%s' % (user, passwd)).replace('\n', '')
>request = urllib2.Request(url, data, headers={"Authorization" : "Basic %s" % >base64string})
>response = urllib2.urlopen(request).read()
>response_json = json.loads(response)
>response_status = response_json['status']
>status_code = response_status['statusCode']
>status = response_status['status']
>message = response_status['message']
>print status_code , status, message
>```

### 2. httplib2
>```python
>import urllib, httplib2
>github_url = ''
>h = httplib2.Http(".cache")
>h.add_credentials("user", "******", ""
>data = urllib.urlencode({"name":"test"})
>resp, content = h.request(github_url, "POST", data)
>print content
>```

### 3. pycurl
>```python
>import pycurl, json
>github_url = ""
>user_pwd = "user:*****"
>data = json.dumps({"name": "test_repo", "description": "Some test repo"})
>c = pycurl.Curl()
>c.setopt(pycurl.URL, github_url)
>c.setopt(pycurl.USERPWD, user_pwd)
>c.setopt(pycurl.POST, 1)
>c.setopt(pycurl.POSTFIELDS, data)
>c.perform()
>```

### 4. requests
>```python
>import requests, json
>github_url = ""
>data = json.dumps({'name':'test', 'description':'some test repo'}) 
>r = requests.post(github_url, data, auth=('user', '*****'))
>print r.json
>```


## 11. jira

### 1. install
>https://github.com/pycontribs/jira/commits/master

### 2. import 
```python
from jira import JIRA
```

### 3. 与jira服务器建立连接
```python
jira = JIRA('http://localhost/jira/',basic_auth=('username', 'password'))
```

### 4. 创建issue 1
```python
issue_dict= {
    'project': {'id': 11107},
    'summary': 'issue概要',
    'description': 'issue描述\n第二行',
    'issuetype': {'name': 'Bug'},
    'timetracking': {
        'originalEstimate': '1h',
        'remainingEstimate': '1h',              
    },
    'components':[{'name': '一个模块'}],
    'priority': {'name': 'Major'},
    'assignee':{'name': 'username'},
    'versions':[{'name':'V1.0'}],
}

new_issue = jira.create_issue(fields=issue_dict)
```

### 5. 创建issue 2
```python
new_issue = jira.create_issue(project='PROJ_key_or_id', summary='New issue from jira-python',
description='Look into this one', issuetype={'name': 'Bug'})
```

### 6. 修改issue
```python
issue = jira.issue('JIRA-1')
issue.update(versions=[{"name":'V1.1'}])
issue.update(labels=['Label A','Label B'])
issue.update(components=[{'name': 'Xcomponent'}])
issue.update(summary='new summary', description='A new summary was added')
issue.update(assignee={'name': 'new_user'}) 

issue_dict= {
    'summary': 'issue概要',
    'description': 'issue描述\n第二行',
}
issue.update(fields=issue_dict)
```

### 7. 获取特定issue
```python
issue = jira.issue('JIRA-1')
issue = jira.issue('JRA-1330', fields='summary,description，comment')

summary = issue.fields.summary
description = issue.fields.description
```

### 8. 查询issues
```python
#使用JQL进行查询
issues = jira.search_issues('project=PROJ')

#检索第一个标题中含有‘问题’的issue的所有comment
issues = jira.search_issues(jql_str='project = a_project AND summary ~"问题"', maxResults=1,fields='comment')

#查看comment作者
issues[0].fields.comment.comments[0].author.displayName
```

### 9. collections模块
>这个模块实现了特定目标的容器，以提供Python标准内建容器 dict、list、set、tuple 的替代选择。
* Counter：字典的子类，提供了可哈希对象的计数功能
* defaultdict：字典的子类，提供了一个工厂函数，为字典查询提供了默认值
* OrderedDict：字典的子类，保留了他们被添加的顺序
* namedtuple：创建命名元组子类的工厂函数
* deque：类似列表容器，实现了在两端快速添加(append)和弹出(pop)
* ChainMap：类似字典的容器类，将多个映射集合到一个视图里面

#### Counter
