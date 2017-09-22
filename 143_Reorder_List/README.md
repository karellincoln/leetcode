## 问题

Given a singly linked list L: L0?L1?…?Ln-1?Ln,
reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

## 想法

要实现很简单，主要要减少链表的遍历次数。
1. 对链表的操作不熟悉，想不出如何使用链表就可以直接从尾到头的访问链表。
    - 使用数组解决。
2. 通过查看别人的代码发现用链表也挺简单的。
    - 将链表分成两段（使用两个指针，一个跳一次，一个跳两次最后等到两段链表）
    - 将第二段链表reverse。
    - 将两段链表merge。

对自己的思维评价：
一开始一直跳不出反向遍历的思想，思想还是比较僵化的。像上面的方法二，（想我竟然知道不可以反向遍历，那为什么不想以为一种，将反向的链表颠倒过来。这样就可以直接遍历了。这也就是方法二的思想）一步步来，没有条件创造条件。