## 278. First Bad Version

### 问题
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API `bool isBadVersion(version)` which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

### 思考
又被>>右移符号的优先级坑了。

### 代码
```
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int first = 1, end = n;
        int res;
        while (first <= end) {
            int mid = first + ((end - first) >> 1);
            if (isBadVersion(mid) == true) {
                res = mid;
                end = mid - 1;
            } else {
                first = mid + 1;
            }
        }
        return res;
    }
};

```

## 279. Perfect Squares

### 问题

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.


### 思考
下面的代码是巨慢无比的代码，因为没有好的思路。
**Explanation:**   

I happen to have given a little talk about just this topic a while back in a number theory seminar. This problem is completely solved, in the sense of being reduced to simple checks of a number's prime factorization. A natural number is...
```
... a square if and only if each prime factor occurs to an even power in the number's prime factorization.
... a sum of two squares if and only if each prime factor that's 3 modulo 4 occurs to an even power in the number's prime factorization.
... a sum of three squares if and only if it's not of the form 4a(8b+7) with integers a and b.
... a sum of four squares. Period. No condition. You never need more than four.
Of course single squares can also be identified by comparing a given number with the square of the rounded root of the number.
```

The problem statement says "1, 4, 9, 16, ...", for some reason apparently excluding 0, but it really is a perfect square and the above theorems do consider it one. With that, you can for example always extend a sum of two squares a2+b2 to the sum of three squares a2+b2+02. Put differently, if n isn't a sum of three squares, then it also isn't a sum of two squares. So you can read the above statements as "... a sum of m (or fewer) squares". Thanks to ruben3 for asking about this in the comments.

In my above solutions, I first divide the given number by 4 as often as possible and then do the three-squares check. Dividing by 4 doesn't affect the other checks, and the n % 8 == 7 is cheaper than the prime factorization, so this saves time in cases where we do need four squares.

Armed with just the knowledge that you never need more than four squares, it's also easy to write O(n) solutions, e.gS

### 代码
```
class Solution {
public:
    int numSquares(int n) {
        if (numSq.find(n) != numSq.end()) return numSq[n];
        if (n == 0) return 0;
        int min = INT_MAX;
        for (int i = 1; i * i <= n; ++i) {
            int count = numSquares(n - i * i);
            if (min > 1 + count) min = 1 + count;
        }
        numSq[n] = min;
        return min;
    }
    unordered_map<int, int> numSq;
};

```


## 282. Expression Add Operators

### 问题

Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
```
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
```

### 思考


### 代码
```


```


## 283. Move Zeroes
### 问题

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = \[0, 1, 0, 3, 12\], after calling your function, nums should be \[1, 3, 12, 0, 0\].

Note:   
1. You must do this in-place without making a copy of the array.
2. Minimize the total number of operations.


### 思考
和插入排序比较像。

### 代码
```
class Solution {
public:
    void swap(int &a, int &b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    void moveZeroes(vector<int>& nums) {
        int zero_position = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0 && zero_position == -1) zero_position = i;
            else if (nums[i] != 0 && zero_position != -1) {
                swap(nums[i], nums[zero_position]);
                ++zero_position;
            }
        }
    }
};

```
