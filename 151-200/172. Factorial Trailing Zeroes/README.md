## 172. Factorial Trailing Zeroes

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

## 思考

这是一个数学问题， 可以十分简单的计算


## 代码

```
func trailingZeroes(n int) int {
    var res int
    for ; n > 0; n /= 5 {
        res += n / 5
    }
    return res
}
```
