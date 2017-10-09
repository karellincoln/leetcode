## 问题

Given an input string, reverse the string word by word.

For example,
```
Given s = "the sky is blue",
return "blue is sky the".
```

Update (2015-02-12):
For C programmers: Try to solve it **in-place in O(1) space**.

Clarification:
1. What constitutes a word?
    A sequence of non-space characters constitutes a word.
2. Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
3. How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.

## 思考

1. 一开始是想直接使用栈解决问题的。但是看到要使用O(1)的空间。
2. 就想到要在原数组上替换最简单的方式是两个头尾指针依次替换，但是这样就将单词的顺序也替换了，其实下一步很容易想到就是再对每个单词做一次替换（但是能这么快想到是因为之前看了《剑指offer》这本书）
3. 现在剩下一个问题就是上面Clarification中提到的空格的处理。在2.中提到的方案中有两个解决方案：
    1. 先整个旋转，再对每个单词做旋转，同时去掉多余的空格。
    2. 去掉多余的空格，对每个单词旋转，再总的旋转。
写完发现两个是一样的只是顺序变了。 

实现看代码。
