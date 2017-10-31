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
