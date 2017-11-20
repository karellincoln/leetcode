## 231. Power of Two

### 问题
Given an integer, write a function to determine if it is a power of two.

### 思考

Power of 2 means only one bit of n is '1', so use the trick n&(n-1)==0 to judge whether that is the case

### 代码

```
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return !(n&(n - 1));
    }
};
```

## 232. Implement Queue using Stacks

### 问题
Implement the following operations of a queue using stacks.
```
push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
```
Notes:
```
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
```

### 思考
两个栈。

### 代码
```
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        int t = out.top();
        out.pop();
        return t;
    }
    
    /** Get the front element. */
    int peek() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty() && out.empty();
    }
    stack<int> in;
    stack<int> out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

```


## 233. Number of Digit One

### 问题
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:    
Given n = 13,    
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

### 思考
这种多种情况的找规律的题目处理的还不好。   
k要为long类型，因为*10之后int会越界。

### 代码
```
class Solution {
public:
    int countDigitOne(int n) {
        int ones = 0;
        for (long k = 1; k <= n; k *= 10) {
            int r = n/k, m = n%k;
            ones += (r + 8) / 10 * k + (r % 10 == 1 ? m + 1 : 0);
        }
        
        return ones;
    }
};

```


## 234. Palindrome Linked List

### 问题
Given a singly linked list, determine if it is a palindrome.

Follow up:   
Could you do it in O(n) time and O(1) space?

### 思考
不是很有趣。

### 代码
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int count(ListNode* head) {
        int c = 0;
        while (head != NULL) {
            head = head->next;
            ++c;
        }
        return c;
    }
    ListNode* reverseList(ListNode *head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        int l = count(head);
        if (l < 2) return true;
        ListNode *second = head;
        for (int i = 0; i < l/2; ++i) {
            second = second->next;
        }
        second = (l%2) ? second->next : second;
        second = reverseList(second);
        
        while (second != NULL) {
            if (head->val != second->val) return false;
            second = second->next;
            head = head->next;
        }
        
        return true;
    }
};

```

## 235. Lowest Common Ancestor of a Binary Search Tree

### 问题
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
```
        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
```

For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

### 思考


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p -> val < root -> val && q -> val < root -> val)
            return lowestCommonAncestor(root -> left, p, q);
        if (p -> val > root -> val && q -> val > root -> val)
            return lowestCommonAncestor(root -> right, p, q);
        return root;
    }
};

```


## 236. Lowest Common Ancestor of a Binary Tree

### 问题

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
```
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
```

For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
### 思考


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || p == root || q == root) return root;
        
        TreeNode *left = lowestCommonAncestor(root -> left, p, q);
        TreeNode *right = lowestCommonAncestor(root -> right, p, q);
        
        return !left ? right : !right ? left : root;
    }
};

```


## 237. Delete Node in a Linked List

### 问题

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is `1 -> 2 -> 3 -> 4` and you are given the third node with value 3, the linked list should become `1 -> 2 -> 4` after calling your function.

### 思考
借用下面一句话。
This question is stupid and should be deleted intermediately.

### 代码
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode *tmp = node->next;
        node->next = tmp->next;
        delete tmp;
    }
};

```

## 238. Product of Array Except Self

### 问题

Given an array of n integers where n > 1, `nums`, return an array `output` such that `output[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

Solve it **without division** and in O(n).

For example, given `[1,2,3,4]`, return `[24,12,8,6]`.

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)


### 思考
确实没有想到可以将其分成两部分计算，被自己分成的前和后。

### 代码
```

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        
        for(int i = 0, tmp = 1; i < nums.size(); ++i) {
            res[i] = tmp;
            tmp *= nums[i];
        }
        
        for (int i = nums.size() - 1, tmp = 1; i >= 0; --i) {
            res[i] *= tmp;
            tmp *= nums[i];
        }
        
        return res;
    }
};
```


## 239. Sliding Window Maximum

### 问题

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = `[1,3,-1,-3,5,3,6,7]`, and k = 3.
```
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

Therefore, return the max sliding window as `[3,3,5,5,6,7]`.

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

### 思考
这道题目不是我自己想出来的，但是还是很有参考价值。我应该是知道单调队列这个东西的。但是我从来没有想过可以这么使用。

```
Sliding window minimum/maximum = monotonic queue. I smelled the solution just when I read the title.
This is essentially same idea as others' deque solution, but this is much more standardized and modulized. If you ever need to use it in your real product, this code is definitely more preferable.

What does Monoqueue do here:

It has three basic options:

push: push an element into the queue; O (1) (amortized)

pop: pop an element out of the queue; O(1) (pop = remove, it can't report this element)

max: report the max element in queue;O(1)
```
单调队列就是(a1, a2, a3,...) 有 a1 <= a2 <= a3 <=... 的性质，但是我没有想到可以加入下面的计数方式。   


### 代码
```
class MonoQueue {
public:
    void push(int val) {
        int count = 0;
        while (!monoQueue.empty() && monoQueue.back().first < val) {
            count += monoQueue.back().second + 1;
            monoQueue.pop_back();
        }
        monoQueue.push_back(make_pair(val, count));
    }
    void pop() {
        if (monoQueue.front().second > 0) {
            --monoQueue.front().second;
            return;
        }
        monoQueue.pop_front();
    }
    int max() {
        return monoQueue.front().first;
    }
private:
    deque<pair<int,int> > monoQueue; // first: val, second: how many elements were deleted before it.
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MonoQueue mq;
        
        for (int i = 0; i < k - 1; ++i) {
            mq.push(nums[i]);
        }
        for (int i = k - 1 ; i < nums.size(); ++i) {
            mq.push(nums[i]);
            res.push_back(mq.max());
            mq.pop();
        }
        
        return res;
    }
};

```

## 240. Search a 2D Matrix II

### 问题
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:
```
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
```
Given target = 5, return true.

Given target = 20, return false.

### 思考
我好像是做过这道题目的，在剑指offer中也出现过。
使用递归的方式，我出错了几次，而且代码速度很慢。
O(m + n) 复杂度的算法。

### 代码
```
class Solution {
public:
    bool help(vector<vector<int> >& matrix, int sr, int sc, int er, int ec, int target) {
        if (sr >= er || sc >= ec) return false;
        int mr = (sr + er) / 2, mc = (sc + ec) / 2;
        if (matrix[mr][mc] == target) return true;
        else if (matrix[mr][mc] < target) {
            return help(matrix, sr, mc + 1, mr + 1, ec, target) || 
                   help(matrix, mr + 1, sc, er, mc + 1, target) || 
                   help(matrix, mr + 1, mc + 1, er, ec, target);
        }
        
        return help(matrix, sr, sc, mr, mc, target) ||
               help(matrix, sr, mc, mr, ec, target) ||
               help(matrix, mr, sc, er, mc, target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        
        return help(matrix, 0, 0, matrix.size(), matrix[0].size(), target);
    }
};

O(m + n) 复杂度的算法。
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0) return false;
    
    int i = 0;
    int j = matrix[0].size() - 1;
    while (i < matrix.size() && j >= 0) {
        if (matrix[i][j] == target) return true;
        
        if (matrix[i][j] < target) {
            ++i;
        }
        else --j;
    }
    
    return false;
}



```





