## 问题

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
```
X X X X
X O O X
X X O X
X O X X
```

After running your function, the board should be:
```
X X X X
X X X X
X X X X
X O X X
```


## 想法

一开始的想法：周围是活的， 但是一开始想能不能通过bfs解决问题。用bfs比较麻烦。

思维漏洞：
1. 也没有考虑到可以将活的O替换成其他字符，只是想到需要一个数组来记录哪一些是活的，哪一些是死的。
2. 在考虑遍历方法的时候没有想到dfs，只是使用数组的思想，按照行或者列遍历顺序。