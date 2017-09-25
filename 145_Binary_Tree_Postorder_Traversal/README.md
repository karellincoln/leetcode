## 问题

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
```
   1
    \
     2
    /
   3
```
return [3,2,1].

**Note**: Recursive solution is trivial, could you do it iteratively?

## 想法

分析：
Hi, this is a fundamental and yet classic problem. I share my three solutions here:
1. Iterative solution using stack --- O(n) time and O(n) space;
2. Recursive solution --- O(n) time and O(n) space (considering the spaces of function call stack);
3. Morris traversal --- O(n) time and O(1) space!!!

**自己还是太孤陋寡闻了。要多学习。**

1. 一开始小看了这个问题。觉得会和前序遍历一样简单。最后发现虽然也可以用堆栈解决，但是自己的想法还是太复杂了点。
   1. 一开始我自己的想法（先进栈，同时将左右子树的指针赋值为NULL，但是这样改变了树的结构。迟迟不想这样写）
   2. 觉得别人的遍历写的才精彩。除了使用堆栈外，只添加了两个指针，一个是当前的指针（采用遍历的思想指向当前访问的节点），另一个是该节点及子节点已经完成访问的节点（主要作用是取代我上面的NULL的标识，右节点已经访问过来则说明自己也可以出栈了）。
   3. **需要多用笔，多画一下流程图清晰一下流程** （思考需要处理的问题有哪一些，有什么比较好的办法可以解决问题） 不然很容易有大概的想法，但是实现却不好。
2. 上面只是简单的使用堆栈实现。进过别人的介绍还有一种更省空间的算法。Morris
   1. [Morris Traversal方法遍历二叉树（非递归，不用栈，O(1)空间）](http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html)
   2. [线索二叉树](https://en.wikipedia.org/wiki/Threaded_binary_tree#The_array_of_Inorder_traversal)
      1. 动机：递归的使用了多余的空间。
      2. 定义："A binary tree is threaded by making all right child pointers that would normally be null point to the inorder successor of the node (if it exists), and all left child pointers that would normally be null point to the inorder predecessor of the node."
      3. 中序遍历：
         **步骤：**
         1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
         2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
            1. 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
            2.  如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。
            3. 重复以上1、2直到当前节点为空。
         ![中序遍历过程](http://images.cnitblog.com/blog/300640/201306/14214057-7cc645706e7741e3b5ed62b320000354.jpg)
      4. 后序遍历:
         **步骤**
         当前节点设置为临时节点dump。
         1. 如果当前节点的左孩子为空，则将其右孩子作为当前节点。
         2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
            1. 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
            2. 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。倒序输出从当前节点的左孩子到该前驱节点这条路径上的所有节点。当前节点更新为当前节点的右孩子。
            3. 重复以上1、2直到当前节点为空。
        ![后序遍历过程](http://images.cnitblog.com/blog/300640/201306/15165951-7991525829134fb3beefed9fbf7e0536.jpg)
