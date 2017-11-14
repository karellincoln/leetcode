## 211. Add and Search Word - Data structure design

### 问题
Design a data structure that supports the following two operations:
```
void addWord(word)
bool search(word)
```
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:
```
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
```

### 思考
看总的提示。
因为一开始写的一些小错误，一直修改。导致一直存在小bug没有完全改完。以后修改代码一定要有总体观念。

### 代码

```
class TrieNode{
public:
    TrieNode():word(false) {
        memset(children, 0, sizeof(children));
    }
    bool word;
    TrieNode* children[26];
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary():root() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        tmp = &root;
        for(int i = 0; i < word.size(); ++i) {
            int k = word[i] - 'a';
            if(tmp->children[k] == NULL) {
                tmp->children[k] = new TrieNode();
            }
            tmp = tmp->children[k];
        }
        tmp->word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool searchDFS(TrieNode *r, string word) {
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == '.') {
                int result = false;
                for (int j = 0; j < 26; ++j) {
                    if (r->children[j] != NULL) result = result || searchDFS(r->children[j], word.substr(i + 1));
                }
                return result;
            }
            else {
                if (r->children[word[i] - 'a'] == NULL) return false;
                r = r->children[word[i]-'a'];
            }
        }
        return r->word;
    }
    bool search(string word) {
        return searchDFS(&root, word);
    }
    
    TrieNode root;
    TrieNode *tmp;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

```

## 212. Word Search II

### 问题

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = \["oath","pea","eat","rain"\] and board =
```
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
```
Return \["eat","oath"\].

### 思考
这个代码，我也是一边写一边思考流程的。只是一开始就定位了我知道要怎么写。而且使用深度优先遍历（递归实现），边界的处理还是比较简单的。所以比较快的实现了。


### 代码

```
class Solution {
    class TrieNode{
    public:
        TrieNode():word(false) {
            memset(children, 0, sizeof(children));
        }
        bool word;
        TrieNode* children[26];
    };
    void addWord(const string word) {
        TrieNode *tmp = &root;
        for(int i = 0; i < word.size(); ++i) {
            int k = word[i] - 'a';
            if(tmp->children[k] == NULL) {
                tmp->children[k] = new TrieNode();
            }
            tmp = tmp->children[k];
        }
        tmp->word = true;
    }
    void createTrie(const vector<string> &words) {
        for (auto w : words) {
            addWord(w);
        }
    }
    void doTask(vector<vector<char> > &board, vector<vector<bool> > &visit, TrieNode *trie, int row, int col){
        visit[row][col] = true;
        word.push_back(board[row][col]);
        DFSHelp(trie->children[board[row][col] - 'a'] , board, row, col, visit);
        word.pop_back();
        visit[row][col] = false;
    }
    void DFSHelp(TrieNode *trie, vector<vector<char> > &board, int row, int col, vector<vector<bool> > &visit) {
        if (trie->word == true) { result.push_back(word); trie->word = false; }
        if (row - 1 >=0 && visit[row - 1][col] == false && trie->children[board[row -1][col]-'a'] != NULL)
            doTask(board, visit, trie, row - 1, col);
        if (row + 1 < board.size() && visit[row + 1][col] == false && trie->children[board[row + 1][col]-'a'] != NULL)
            doTask(board, visit, trie, row + 1, col);
        if (col - 1 >=0 && visit[row][col - 1] == false && trie->children[board[row][col - 1]-'a'] != NULL)
            doTask(board, visit, trie, row, col - 1);
        if (col + 1 < board[0].size() && visit[row][col + 1] == false && trie->children[board[row][col + 1]-'a'] != NULL)
            doTask(board, visit, trie, row, col + 1);
    }
    void findWordsDFS(vector<vector<char> > &board) {
        if (board.size() == 0) return;
        vector<vector<bool> > visit(board.size(), vector<bool>(board[0].size(), false));
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if(root.children[board[i][j] - 'a'] != NULL) doTask(board, visit, &root, i, j);
            }
        }
    }
    
    TrieNode root;
    vector<string> result;
    string word;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        createTrie(words);
        findWordsDFS(board);
        
        return result;
    }
    
};
```


## 213. House Robber II

### 问题

**Note:** This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are **arranged in a circle**. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight **without alerting the police.**


### 思考

现在相比之前加了一个条件既前后不能同时抢。那就可以分解问题，分成不抢前的情况，和不抢后的情况。

### 代码

```
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int m;
        int rob = 0, norob = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int currRob = norob + nums[i];
            norob = max(norob, rob);
            rob = currRob;
        }
        m = max(rob, norob);
        rob = 0, norob = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int currRob = norob + nums[i];
            norob = max(norob, rob);
            rob = currRob;
        }
        m = max(m, max(rob, norob));
        
        return m;
    }
};

```


## 214. Shortest Palindrome

### 题目
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:
```
Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
```

### 思考

[从头到尾彻底理解KMP（2014年8月22日版）](http://blog.csdn.net/v_july_v/article/details/7041827) 很好的讲解。
最快的算法在理解上是最简单的。


### 代码

```
// 超时的代码。一个很奇怪的错误，我还是没有想出原因。就算没有超时那个超长的代码数组我得出的结果也是错误的。难道是这种hash算法发生碰撞了。
class Solution {
    int stringHash(string &s, int start, int end) {
        unsigned hash = 0;
        for (int i = start; i < end; ++i) {
            hash = s[i] + hash * 131;
        }
        return hash & 0x7fffffff;
    }
    int reverseHash(string &s, int end, int start) {
        unsigned hash = 0;
        for (int i = end; i > start; --i) {
            hash = s[i] + hash * 131;
        }
        return hash & 0x7fffffff;
    }
public:
    string shortestPalindrome(string s) {
        string res;
        map<int, int> m;
        for (int i = 0; i < s.size(); ++i) {
            int h = stringHash(s, 0, i + 1);
            m[h] = i;
        }
        for (int i = s.size() - 1; i >= 0; --i) {
            int h = reverseHash(s, i, -1);
            if (m.find(h) != m.end()) {
                string suffix;
                for (int k = s.size() -1; k > m[h]; k--) {
                    suffix.push_back(s[k]);
                }
                res = suffix + s;
                break;
            }
        }
        
        return res;
    }
};

// 使用kmp算法解决的。
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;
        
        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = (j += l[i] == l[j]);
        }
        
        return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
    }
};

// 最快的代码。
class Solution {
public:
    string shortestPalindrome(string str) {
        int sz(str.size());
        if(sz < 2)
            return str;
        int len(1);

        for(int i = 0; i < (sz + 1)/2; ) {
            int start(i - 1), end(i + 1);
            
            while((end < sz) && (str[end] == str[end - 1])) end++;
            
            i = end;
            
            while((start >= 0) && (end < sz) && (str[start] == str[end]))
                start--, end++;
            if(start ==  -1)
                len = max(len, end - start - 1);
        }
        //cout << len << endl;
        string s(str.substr(len));
        reverse(s.begin(), s.end());
        return s + str;
    }
};

```



## 215. Kth Largest Element in an Array

### 问题
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,   
Given \[3,2,1,5,6,4\] and k = 2, return 5.

### 思考
在快排中讲过这个了。

### 代码

```
class Solution {
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    int help(vector<int> &nums, int s, int e, int k){
        int start = s;
        int end = e - 1;
        while (start <= end) {
            while(nums[start] > nums[e]) ++start;
            while(nums[end] <= nums[e] && end > start) --end;
            if (start >= end) break;
            swap(nums[start], nums[end]);
        }
        swap(nums[e], nums[start]);
        if (start + 1 == k) return nums[start];
        else if (start + 1 > k) return help(nums, s, start - 1, k);
        return help(nums, start + 1, e, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return help(nums, 0, nums.size() - 1, k);
    }
};

```

## 216. Combination Sum III

### 问题

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:
```
Input: k = 3, n = 7
```
Output:
```
[[1,2,4]]
```
Example 2:
```
Input: k = 3, n = 9
```
Output:
```
[[1,2,6], [1,3,5], [2,3,4]]
```

### 思考
那n不是要小于45吗？
这次代码写的比较顺了。

### 代码

```
class Solution {
public:
    void help(int start, int k, int n) {
        if (k == 0 && n == 0) { result.push_back(combination); return; }
        if (start + 1 > n || k == 0 || n/k > 9) {return;}
        for (int i = start + 1; i <= n/k; ++i) {
            combination.push_back(i);
            help(i, k - 1, n - i);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k == 0 || n / k > 9) return result;
        for (int i = 1; i <= n/k; ++i) {
            combination.push_back(i);
            help(i, k - 1, n - i);
            combination.pop_back();
        }
        
        return result;
    }
    vector<vector<int> > result;
    vector<int> combination;
};

```


## 217. Contains Duplicate

### 问题

Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

### 思考
一开始的话是先排序然后直接遍历。但是其实是知道用映射比较好的。但是想到自己实现为了解决冲突挺麻烦的，还有查找也是一个问题。还好有stl库。
但是好尴尬，好像排序后遍历的时间比map的更短。像map，set这些操作都是有固定的时间花销的。

### 代码

```
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> map;
        for (auto a : nums) {
            if (map.find(a) != map.end()) return true;
            else map[a] = 1;
        }
        return false;
    }
};

```


## 219. Contains Duplicate II

### 问题

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

### 思考
直接根据217的思想修改。

### 代码
```
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) != map.end()) {
                if (i - map[nums[i]] <= k) return true;
                else map[nums[i]] = i;
            }
            else map[nums[i]] = i;
        }
        return false;
    }
};

```


