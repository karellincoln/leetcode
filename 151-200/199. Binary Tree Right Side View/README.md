## 199. Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:   
Given the following binary tree,
>   1            <---
> /   \
>2     3         <---
> \     \
>  5     4       <---
You should return \[1, 3, 4\].

## 思考

这种问题对我来说还比198容易解决一些。现在我已经比较熟悉使用递归解决问题了，但是对于动态规划还是不熟悉。这个是遍历树的一种操作，可以使用一个数组记录当前视图的情况。如果有该层右边有新的点就更新它

但是在写go的时候还是由于对go的指针，还有go的函数是传值的，主要还是slice的append操作的特殊性。现在写出来的代码比较丑，以后熟悉go之后改进。

## 代码

```
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func help(root *TreeNode, result *[]int, depth int) {
    if root == nil {
        return
    }
    if len(*result) == depth {
        *result = append(*result, root.Val)
    } else {
        (*result)[depth] = root.Val
    }
    
    help(root.Left, result, depth + 1)
    help(root.Right, result, depth + 1)
    
}

func rightSideView(root *TreeNode) []int {
    result := make([]int, 0)
    
    help(root, &result, 0)
    
    return result;
}
```
