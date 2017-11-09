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
