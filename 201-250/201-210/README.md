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
