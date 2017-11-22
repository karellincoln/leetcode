## 241. Different Ways to Add Parentheses

### 问题

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:
```
Input: "2-1-1".
((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]
```

Example 2
```
Input: "2*3-4*5"
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
```

### 思考
一开始觉得好难啊。怎么可能是medium的呢。后来通过列表达式想清楚了之后也不难解决。    
n表示数字的个数有。   
`a[n] = a[1]*a[n-1] + a[2]*a[n-2] + ... + a[n-1]*a[1].`   根据表达式可以使用递归解决。如果需要可以建立map,`string->vector<int>`的映射

### 代码
```
class Solution {
public:
    bool is_op(char op) {
        return op == '+' || op == '-' || op == '*';
    }
    void push_val(vector<int> &res, int a, int b, char op) {
        switch (op) {
            case '+':
                res.push_back(a + b);
                break;
            case '-':
                res.push_back(a - b);
                break;
            case '*':
                res.push_back(a * b);
                break;
            default:
                break;
        }
    }
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); ++i) {
            if (is_op(input[i])) {
                vector<int> res1 = diffWaysToCompute(input.substr(0, i));
                vector<int> res2 = diffWaysToCompute(input.substr(i + 1));
                
                for (auto r1 : res1) 
                    for (auto r2 : res2)
                        push_val(res, r1, r2, input[i]);
            }
        }
        if (res.size() == 0) {
            res.push_back(stoi(input));
        }
        
        return res;
        
    }
};

```

## 242. Valid Anagram

### 问题

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
```
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
```
Note:   
You may assume the string contains only lowercase alphabets.

Follow up:   
What if the inputs contain unicode characters? How would you adapt your solution to such case?

### 思考
就这样。

### 代码
```
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> char_num(26, 0);
        for (auto c : s) {
            ++char_num[c-'a'];
        }
        for (auto c : t) {
            if (char_num[c - 'a'] == 0) return false;
            else --char_num[c-'a'];
        }
        for (auto a : char_num) {
            if (a != 0) return false;
        }
        return true;
    }
};

```

## 257. Binary Tree Paths

### 问题

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:
```
   1
 /   \
2     3
 \
  5
```
All root-to-leaf paths are:

`["1->2->5", "1->3"]`
### 思考
虽然思路一下子就想到了，但是代码还是写了挺久的。要加把劲啊。

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
    void help(TreeNode* root, string path) {
        if (root->left == NULL && root->right == NULL) {
            all_path.push_back(path);
            return;
        }
        if (root->left != NULL) help(root->left, path + "->" + to_string(root->left->val));
        if (root->right != NULL) help(root->right, path + "->" + to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return all_path;
        help(root, to_string(root->val));
        return all_path;
    }
    
    vector<string> all_path;
};

```



