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










