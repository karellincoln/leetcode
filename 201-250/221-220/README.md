## 221. Maximal Square

### 问题

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:
```
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
```
Return 4.

### 思考
每个点bfs遍历。还是很不高效的，如果全部为1的话做了很多无用功。
思考使用dp。dp还是很简约，美妙的。

### 代码

```
class Solution {
public:
    void bfs(vector<vector<char> > &matrix, int row, int col, int depth) {
        max = depth*depth > max ? depth*depth : max;
        if (matrix.size() <= row + depth || matrix[0].size() <= col + depth) return;
        for (int i = col; i < col + depth + 1; ++i) {
            if (matrix[row + depth][i] == '0') return;
        }
        for (int i = row; i < row + depth; ++i) {
            if (matrix[i][col + depth] == '0') return;
        }
        bfs(matrix, row, col, depth + 1);
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        max = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') bfs(matrix, i, j, 1);
            }
        }
        return max;
    }
    
    int max;
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '0') dp[i][j] = 0;
                else if(i == 0 || j == 0) dp[i][j] = (matrix[i][j] == '1');
                else if(dp[i][j-1] == dp[i-1][j]) dp[i][j] = dp[i][j-1] + (matrix[i - dp[i][j-1]][j-dp[i-1][j]]== '1'?1:0);
                else dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;
                ans = max(ans,dp[i][j]);
            }
        }
        
        return ans*ans;   
    }
};

```


## 222. Count Complete Tree Nodes

### 问题

Given a complete binary tree, count the number of nodes.

[Definition of a complete binary tree from Wikipedia:](https://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees)    
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

### 思考
主要要解决的是最下面一层有多少个节点。觉得其他方法不会比傻傻的一个个算快啊。
确实可以通过使用左右树的深度做一些简便的操作。
<< 左移和右移的优先级真的是害死人啊。它们的优先级为什么那么低啊。

### 代码

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};
时间超时。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode *root) {
        int height = 0;
        while (root != NULL) {
            ++height;
            root = root -> left;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int h = height(root);
        if (height(root->right) == h - 1) return (1 << (h - 1)) + countNodes(root -> right);
        return (1 << (h - 2)) + countNodes(root -> left);
    }
};

```

