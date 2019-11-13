### 1.Reverse Integer(7)

#### Python
```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        rev_num = 0
        if x == 0:
            return 0
        flg = x/abs(x)
        x = abs(x)
        while x != 0 :
            rev_num = rev_num*10 + x%10
            x = x/10
        rev_num = rev_num*flg
        if rev_num<-2147483648 or rev_num > 2147483647:
            return 0
        return rev_num
```
1. python2 的负数，和正数的除法不一样，这和乡下取整有关系。(-5%10) 结果是 -1,而不是 0；
2. 注意这个题的方法，是除以10 然后 取余。
3. 注意题目的取值范围。

### 2.Palindrome Number(9)
#### Python
方法一：
```python
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if str(x) == str(x)[::-1]:
            return True
        else:
            return False
```
20ms 范例。tip : 不一定转字符串就效率低下。这个方法就是数字转字符串，因为str也是另外一种list,然后用切片，给它翻转了；```mylist[start:end:step]```

方法二:
```python
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0 :
            return False
        elif x == 0 :
            return True

        rev_num = 0
        temp = x
        while temp > 0:
            rev_num = rev_num * 10 + temp % 10
            temp = temp / 10
        if rev_num == x:
            return True
        return False
```
取余的方式翻转，然后判断与原来的相等；tip：自己想的，效率64ms；

### 3.Roman to Integer(13)
