## 201. Bitwise AND of Numbers Range

### 问题

Given a range \[m, n\] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range \[5, 7\], you should return 4.


### 思考

一开始不相信是直接范围内的所有数直接AND操作之后的值。但是不幸的是搜索之后确实是这样同时也看到了别人的解决技巧。并改进了一下。根据AND之后尾数全为0的特点进行快捷操作

### 代码

```

func rangeBitwiseAnd(m int, n int) int {
    var num uint
    for m != n {
        num ++
        m >>= 1
        n >>= 1
    }
    
    return m << num
}

```


## 202. Happy Number

### 问题
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

```
1 * 1 + 9 * 9 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
```


### 思考

根据题目就是判断死循环嘛， 就像环一样只要访问过相同的节点就会产生。这要记录在出现1之前是有出现相同的数就行了再犹豫int为10位十进制数最大为七百多构建一个1000的布尔数组够用了。就是下面简单的代码了。

### 代码

```
func isHappy(n int) bool {
    var visited [1000]bool
    
    if (n < 1000){
        visited[n] = true
    }
    for n != 1 {
        tmp := 0
        for n > 0 {
            tmp += (n % 10) * (n % 10)
            n /= 10
        }
        if (visited[tmp] == true){
            return false
        }
        visited[tmp] = true
        n = tmp
    }
    
    return true
}

```


## 203. Remove Linked List Elements

### 问题

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

### 思考

链表的操作，按照之前的经验，添加一个额外的头节点。使得头结点的操作变得简单。那这道就没有其他问题了。

### 代码

```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
    var pre_head ListNode
    pre_head.Next = head
    tmp := &pre_head
    for ; tmp.Next != nil;  {
        if tmp.Next.Val == val {
            tmp.Next = tmp.Next.Next
        } else {
            tmp = tmp.Next
        }
    }
    
    return pre_head.Next
}

```

## 204. Count Primes

### 问题

Description:

Count the number of prime numbers less than a non-negative number, n.

### 思考
质数筛选法[Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
```
Input: an integer n > 1.
 
 Let A be an array of Boolean values, indexed by integers 2 to n,
 initially all set to true.
 
 for i = 2, 3, 4, ..., not exceeding √n:
   if A[i] is true:
     for j = i^2, i^2+i, i^2+2i, i^2+3i, ..., not exceeding n:
       A[j] := false.
 
 Output: all i such that A[i] is true.

```


### 代码

```
func countPrimes(n int) int {
    primes := make([]bool, n)
    var sum int
    for i := 2; i < n; i++ {
        if (!primes[i]) {
            sum ++
            for j := i * i; j < n; j += i {
                primes[j] = true
            }
        }
    }
    return sum
}

```


## 205. Isomorphic Strings

### 问题

Given two strings **s** and **t**, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

### 思考
我采用比较简单的方法isomorphic要保证，每个映射唯一切位置相同所以我直接采用数组映射的方法，如果双方都可以成功的映射过去则能够成功，否则不能。

期间记住，go语言没有char类型取代它的可以是byte，或者rune（Unicode）。加深了go变量的传值与传引用的含义，对slice和map的理解更好了。

### 代码

```
func isIsomorphic(s string, t string) bool {
    help := func(s, t string) bool {
        m := make(map[rune]rune)
        for i, char := range s {
            if m[rune(char)] == 0 {
                m[rune(char)] = rune(t[i])
            } else if m[rune(char)] != rune(t[i]) {
                return false
            }
        }
        return true
    }
    return help(s, t) && help (t, s)
}
```


## 206. Reverse Linked List

### 问题
Reverse a singly linked list.

### 思考

根据：之前的经验这种操作只要在头中添加一个节点就可以很容易的操作了。但是要善于总结，思考问题。

### 代码

```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    var pre_head ListNode
    var tmp *ListNode
    for head != nil {
        tmp = head
        head = head.Next
        tmp.Next = pre_head.Next
        pre_head.Next = tmp
    }
    
    return pre_head.Next
}

/**
 * 递归的方法
 */

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    
    new_head := reverseList(head.Next)
    head.Next.Next = head
    head.Next = nil
    
    return new_head
}
```


## 207. Course Schedule

There are a total of n courses you have to take, labeled from 0 to n - 1.

### 问题

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:
```
2, [[1,0]]
```
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
```
2, [[1,0],[0,1]]
```
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

### 思考
很明显这是一个拓扑排序问题，而且就是单单纯纯的拓扑排序问题。我一开始没有直接自己实现代码，是在想问题给的数据是一个二元数组，在拓扑排序中不要处理。要不要转换成链接表或者链接矩阵呢？根据别人的代码他们也是这么操作的。

**知识点：**
拓扑排序：
定义：将有向图中的顶点以线性方式进行排序。即对于任何连接自顶点u到顶点v的有向边uv，在最后的排序结果中，顶点u总是在顶点v的前面。

**偏序/全序关系：**   
在我们所有可以选择的课程中，任意两门课程之间的关系要么是确定的(即拥有先后关系)，要么是不确定的(即没有先后关系)，绝对不存在互相矛盾的关系(即环路)。以上就是偏序的意义，    
所谓全序，就是在偏序的基础之上，有向无环图中的任意一对顶点还需要有明确的关系(反映在图中，就是单向连通的关系，注意不能双向连通，那就成环了)。   

**Kahn算法：**   
摘一段维基百科上关于Kahn算法的伪码描述：   
```
L← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edges
while S is non-empty do
    remove a node n from S
    insert n into L
    foreach node m with an edge e from nto m do
        remove edge e from thegraph
        ifm has no other incoming edges then
            insert m into S
if graph has edges then
    return error (graph has at least onecycle)
else 
    return L (a topologically sortedorder)
```
基于bfs，还可以基于DFS。


### 代码

```

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> ind(numCourses,0);
        queue<int> q;
        for(auto a:prerequisites){
            graph[a.second].push_back(a.first);
            ind[a.first]++;
        }
        for(int i=0;i<ind.size();i++){
            if(ind[i]==0) q.push(i);
        }
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(int a:graph[cur]){
                ind[a]--;
                if(ind[a]==0) q.push(a);
            }
        }
        for(int i=0;i<ind.size();i++){
            if(ind[i]!=0) return false;
        }
        return true;
    }
};

```


## 208. Implement Trie (Prefix Tree)

### 问题

Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

### 思考

1. 下面代码重复率比较高，需要重写。
2. trie的知识


### 代码

```
class TrieNode {
public:
    TrieNode(bool w = false):word(w){
        memset(children, 0, sizeof(children));
    }
    bool word;
    TrieNode* children[26];
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie():root(){
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *tmp = &root;
        for(int i = 0; i < word.size(); ++i) {
            int k = word[i] - 'a';
            if (tmp->children[k] == NULL) {
                tmp->children[k] = new TrieNode();
            }
            tmp = tmp->children[k];
        }
        tmp->word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *tmp = &root;
        for(int i = 0; i < word.size(); ++i) {
            int k = word[i] - 'a';
            if (tmp->children[k] == NULL) {
                return false;
            }
            tmp = tmp->children[k];
        }
        return tmp->word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *tmp = &root;
        for(int i = 0; i < prefix.size(); ++i) {
            int k = prefix[i] - 'a';
            if (tmp->children[k] == NULL) {
                return false;
            }
            tmp = tmp->children[k];
        }
        return true;
    }
    
    TrieNode root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

```


## 209. Minimum Size Subarray Sum

### 问题

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array \[2,3,1,2,4,3\] and s = 7,
the subarray \[4,3\] has the minimal length under the problem constraint.

### 思考

这道题的思路一下子就想出来了，但是在编程的时候还是出现了很多小问题。自己的编程能力还是不熟悉。对于流程的思考还不能手到擒来。一开始min，写成max，还有end的停止问题。


### 代码

```
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int min = INT_MAX;
        int sum = 0;
        while (nums.size() > end && sum < s) {sum += nums[end++];}
        if (sum < s) return 0;
        while (nums.size() >= end) {
            while (sum - nums[start] >= s) {sum -= nums[start++];}
            min = min < end - start ? min : end-start;
            sum += nums[end++];
        }
        
        return min;
    }
};

```
