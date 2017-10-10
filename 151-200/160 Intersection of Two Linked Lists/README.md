## 问题

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:
```
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
```
begin to intersect at node c1.

**Notes:**

* If the two linked lists have no intersection at all, return `null`.
* The linked lists must retain their original structure after the function returns.
* You may assume there are no cycles anywhere in the entire linked structure.
* Your code should preferably run in O(n) time and use only O(1) memory.


## 思考

1. 自己的思考，首先两个链表不一样长的，不能直接一个个走当指向同一个时判断为第一个公共点。
    2. 如果可以修改链表则可以将访问过的点指向同一个地址，如果访问的节点已经指向这个地址则为第一个
    3. 走到尾部再依次返回
    4. 上面两个都不行，从尾部往回走在单链表上基本不可能。

查看别人的代码结果却是那么简单。两个链表不一样长，那他们**两个加起来**不是一样长了吗。


