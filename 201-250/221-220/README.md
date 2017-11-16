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


## 223. Rectangle Area

### 问题
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

![Rectangle Area](https://leetcode.com/static/images/problemset/rectangle_area.png)

Assume that the total area is never beyond the maximum possible value of int.
### 思考
下面的代码虽然没有错误但是有一个不好的地方，一开始坐标我是声明为int，但是x2-x1在题目的条件中**越界**了，就改为long类型了。   
**注意**：
int的算法一定要考虑int的边界问题。   
但是其实return area的那个条件是可以提前判断并且可以不使用减法，而是直接两个数比较。

### 代码

```
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long x1, y1, x2, y2;
        long area = long((C - A) * (D - B)) + long((G - E) * (H - F));
        
        x1 = A > E ? A : E;
        y1 = B > F ? B : F;
        
        x2 = C > G ? G : C;
        y2 = D > H ? H : D;
        
        if (x2 - x1 <= 0 || y2 - y1 <= 0) return area;
        
        return area - (x2 - x1) * (y2 - y1);
    }
};

```



## 224. Basic Calculator

### 问题
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
```
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
```

### 思考
简单的栈解决。   
其实并不简单：   
[将中序表达式转变成后缀表达式：](http://blog.csdn.net/sgbfblog/article/details/8001651)   
```
中缀表达式a + b*c + (d * e + f) * g，其转换成后缀表达式则为a b c * + d e * f  + g * +。
转换过程需要用到栈，具体过程如下：
1）如果遇到操作数，我们就直接将其输出。
2）如果遇到操作符，则我们将其放入到栈中，遇到左括号时我们也将其放入栈中。
3）如果遇到一个右括号，则将栈元素弹出，将弹出的操作符输出直到遇到左括号为止。注意，左括号只弹出并不输出。
4）如果遇到任何其他的操作符，如（“+”， “*”，“（”）等，从栈中弹出元素直到遇到发现更低优先级的元素(或者栈为空)为止。弹出完这些元素后，才将遇到的操作符压入到栈中。有一点需要注意，只有在遇到" ) "的情况下我们才弹出" ( "，其他情况我们都不会弹出" ( "。
5）如果我们读到了输入的末尾，则将栈中所有元素依次弹出。
```



### 代码

```
class Solution {
public:
    void cal(){
        int a = num.top(); num.pop();
        int b = num.top(); num.pop();
        char p = op.top(); op.pop();
        switch (p) {
            case '+':
                num.push(a + b);
                break;
            case '-':
                num.push(b - a);
                break;
            default:
                break;
        }
    }
    void calculateSub() {
        while(op.top() != '(') {
            cal();
        }
        op.pop();
    }
    
    void calculateResult() {
        while (!op.empty()) {
            cal();
        }
        result = num.top(); num.pop();
    }
    
    int calculate(string s) {
        for (int i = 0; i < s.size(); ++i) {
            switch(s[i]) {
                case '-':
                case '+':
                    if (op.empty() || op.top() == '(') op.push(s[i]);
                    else {
                        cal();
                        op.push(s[i]);
                    }
                    break;
                case '(':
                    op.push(s[i]);
                    break;
                case ' ':
                    break;
                case ')':
                    calculateSub();
                    break;
                default:
                    int current_num = 0;
                    while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                        current_num = current_num * 10 + s[i] - '0';
                        ++i;
                    }
                    num.push(current_num);
                    --i;
                    break;
            }
        }
        calculateResult();
        return result;
    }
    
    int result;
    stack<int> num;
    stack<char> op;
};

```

## 225. Implement Stack using Queues

### 问题
Implement the following operations of a stack using queues.
```
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
```
Notes:
```
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
```

### 思考

### 代码

```
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t = top();
        q.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

```



## 226. Invert Binary Tree

### 问题

Invert a binary tree.
```
     4
   /   \
  2     7
 / \   / \
1   3 6   9
```
to
```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

### 思考
递归左边右，右变左。

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

```

