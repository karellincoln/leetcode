## 173. Binary Search Tree Iterator

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling **next()** will return the next smallest number in the BST.

**Note:** **next()** and **hasNext()** should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

## 思考

有时候时间复杂度和空间复杂度到成为了对思考问题比较好的解决方案的一种提示。
看到需要O(1)时间和O(h)空间的解决方案，就想到了堆栈。


## 代码

```

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root = NULL) {
        while(root != NULL) {
            path.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !path.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur = path.top();
        path.pop();
        
        int n = cur->val;
        
        if (cur->right != NULL) {
            cur = cur->right;
            while(cur != NULL) {
                path.push(cur);
                cur = cur->left;
            }
        }
        
        return n;
    }
    
    stack<TreeNode *> path;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

```
