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

## 258. Add Digits

### 问题
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:   

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:    
Could you do it without any loop/recursion in O(1) runtime?

### 思考
直接写很简单。   
The problem, widely known as digit root problem, has a congruence formula:

`https://en.wikipedia.org/wiki/Digital_root#Congruence_formula`

For base b (decimal case b = 10), the digit root of an integer is:
```
dr(n) = 0 if n == 0
dr(n) = (b-1) if n != 0 and n % (b-1) == 0
dr(n) = n mod (b-1) if n % (b-1) != 0
or

dr(n) = 1 + (n - 1) % 9
Note here, when n = 0, since (n - 1) % 9 = -1, the return value is zero (correct).
```

From the formula, we can find that the result of this problem is immanently periodic, with period (b-1).

Output sequence for decimals (b = 10):

~input: 0 1 2 3 4 ...
output: 0 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 ....

Henceforth, we can write the following code, whose time and space complexities are both O(1).

Thanks for reading. :)

### 代码
```
class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num > 0) sum += num % 10, num /= 10;
            num = sum;
        }
        return num;
    }
};

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            num = num / 10 + num % 10;
        }
        return num;
    }
};

class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};

```



## 260. Single Number III

### 问题
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:
```
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
```

**Note:**   
The order of the result is not important. So in the above example, \[5, 3\] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

### 思考
先不使用常量空间吧。   
使用unordered_set数据类型可以比较迅速的完成任务   

现在思考特殊的方法。首先出现两次可以简单的使用异或^操作解决。但是两个不同的a，b也会进行异或操作。   
那要怎么将a，b分开的。而且a，b异或之后的值可以给我们什么信息呢。具体的查看下面的代码。

### 代码
```
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> set;
        for(auto a : nums) {
            if (set.find(a) == set.end()) set.insert(a);
            else set.erase(a);
        }
        for(auto s : set) {
            res.push_back(s);
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int aXorb = 0;  // the result of a xor b;
        for (auto item : nums) aXorb ^= item;
        int lastBit = (aXorb & (aXorb - 1)) ^ aXorb;  // the last bit that a diffs b
        int intA = 0, intB = 0;
        for (auto item : nums) {
            // based on the last bit, group the items into groupA(include a) and groupB
            if (item & lastBit) intA = intA ^ item;
            else intB = intB ^ item;
        }
        return vector<int>{intA, intB};   
    }
};

```

## 263. Ugly Number

### 问题
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.

### 思考
直接操作。

### 代码
```
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        while (num > 1) {
            if (num % 2 == 0) num /= 2;
            else if (num % 3 == 0) num /= 3;
            else if (num % 5 == 0) num /= 5;
            else break;
        }
        if (num == 1) return true;
        return false;
    }
};

```

## 264. Ugly Number II

### 问题
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

### 思考

不小心提前看了题目的解决方案。

### 代码
```
class Solution {
public:
    int min(int a, int b, int c) {
        return a > b ? b > c ? c : b : a > c ? c : a;
    }
    int nthUglyNumber(int n) {
        int two_position = 0;
        int three_position = 0;
        int five_position = 0;
        int ugly_number[1690] = {1};
        
        for (int i = 1; i < n; ++i) {
            int a, b, c;
            while (ugly_number[two_position] << 1 <= ugly_number[i - 1]) ++two_position;
            a = ugly_number[two_position] << 1;
            while (ugly_number[three_position] * 3 <= ugly_number[i - 1]) ++three_position;
            b = ugly_number[three_position] * 3;
            while (ugly_number[five_position] * 5 <= ugly_number[i - 1]) ++five_position;
            c = ugly_number[five_position] * 5;
            ugly_number[i] = min(a, b, c);
        }
        
        return ugly_number[n - 1];
    }
};

```


## 268. Missing Number

### 问题
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,     
Given nums = `[0, 1, 3]` return 2.

Note:    
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

### 思考
线性时间，加常量空间的方法没有想出来。有xor， sum。xor觉得不具有普适性，sum的方法还是和正常的。

### 代码
```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res;
        vector<bool> miss(nums.size() + 1, true);
        for (auto a:nums) {
            miss[a] = false;
        }
        for (int i = 0; i < miss.size(); ++i) {
            if (miss[i] == true) { res = i; break; }
        }
        
        return res;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = (size + 1) * size / 2;
        for (auto a:nums) {
            sum -= a;
        }
        return sum;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res ^= i ^ nums[i];
        }
        res ^= nums.size();
        
        return res;
    }
};

```

## 273. Integer to English Words

### 问题
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1.

For example,
```
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
```

### 思考

使用map映射吗。代码的方法还是很简单的，只是实现的时候要注意很多细节。

### 代码
```
const char * const below_20[] =  {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten",
                                        "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
const char * const below_100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        else return int_string(num).substr(1);
    }
    string int_string(int n) {
        if(n >= 1000000000)   return int_string(n / 1000000000) + " Billion" + int_string(n - 1000000000 * (n / 1000000000));
        else if(n >= 1000000) return int_string(n / 1000000) + " Million" + int_string(n - 1000000 * (n / 1000000));
        else if(n >= 1000)    return int_string(n / 1000) + " Thousand" + int_string(n - 1000 * (n / 1000));
        else if(n >= 100)     return int_string(n / 100) + " Hundred" + int_string(n - 100 * (n / 100));
        else if(n >= 20)      return string(" ") + below_100[n / 10 - 2] + int_string(n - 10 * (n / 10));
        else if(n >= 1)       return string(" ") + below_20[n - 1];
        else return "";
    }
};
```


## 274. H-Index

### 问题
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the [definition of h-index on Wikipedia](https://en.wikipedia.org/wiki/H-index): "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = `[3, 0, 6, 1, 5]`, which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

### 思考
主要是不知道h-index的含义，我是根据wiki中的公式直接写的。而根据题目的描述我还看不出来意思，还好N - h 中的-是减号。
使用类似桶排序，统计数据

### 代码
```
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int m = 0;
        for (int i = 0; i < citations.size(); ++i) {
            int v = min(i + 1, citations[i]);
            if (m > v) break;
            else m = v;
        }
        
        return m;
    }
};
// 排序好之后的logN算法。
int hIndex(int* citations, int citationsSize) {
    int lo = 0, hi = citationsSize, mid, index = 0;
    while (lo <= hi) {
        mid = lo + ((hi - lo) >> 1);
        if (citations[citationsSize - mid - 1] > mid) {
            lo = mid + 1;
            index = lo;
        } else {
            hi = mid - 1;
        }
    }
    return index;
}

int hIndex(vector<int>& citations) {
    int size = citations.size();
    vector<int> bucket(size + 1, 0);
    for (auto a:citations) {
        if (a >= size) {
            bucket[size] ++;
        }
        else bucket[a] ++;
    }
    int count = 0;
    for (int i = size; i >= 0; --i) {
        count += bucket[i];
        if (count >= i) return i;
    }
    
    return 0;
}
```

