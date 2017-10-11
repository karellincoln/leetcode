## 169. Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than `⌊ n/2 ⌋`times.

You may assume that the array is non-empty and the majority element always exist in the array.

## 思考

1. 简单的使用映射map，时间是2n
2. 比较巧妙，因为一定有这样的数存在。采用一个计数遇到相同的就加一，不相同就减一。可以保证有正确的解。


## 代码

```
// 方案一
func majorityElement(nums []int) int {
    num_count := make(map[int]int)
    for _, value := range nums {
        num_count[value] ++;
    }
    
    for key, value := range num_count {
        if value > len(nums) / 2 {
            return key
        }
    }
    
    return 0
}


// 方案二
func majorityElement(nums []int) int {
    count, major := 0, nums[0];
    for  _, value := range nums {
        if value == major {
            count ++
        } else if count > 0 {
            count--
        } else {
            count = 1
            major = value
        }
    }
    
    return major
}
```


