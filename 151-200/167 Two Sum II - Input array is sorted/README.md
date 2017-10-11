## 问题

Given an array of integers that is already **sorted in ascending order**, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are **not zero-based.**

You may assume that each input would have exactly one solution and you may not use the same element twice.

```
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
```

## 思考

第一次使用go语言编写代码。

1. 一开始最简单的方法O(nlogn)根据每一个数，target-numbers\[i\]，数组中使用logn的复杂度查找有没有对应的值。
2. 采用映射map 将每个访问过的值的差再存储下来，判断是否与新遍历的值相等。
3. 头尾两个指针和大于target或者小于target。有对应的操作（比较简约）好好

## 代码

```

func twoSum(numbers []int, target int) []int {
    for low, high := 0, len(numbers) - 1; low < high; {
        sum := numbers[low] + numbers[high]
        
        switch {
            case sum < target:
                low++
            case sum > target:
                high--
            default:
                return []int{low + 1, high + 1}
        }
    }
    
    return nil
}

```

