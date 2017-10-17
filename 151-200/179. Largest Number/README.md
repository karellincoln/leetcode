## 179. Largest Number

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given \[3, 30, 34, 5, 9\], the largest formed number is 9534330.

**Note:** The result may be very large, so you need to return a string instead of an integer.


## 思考

一开始就有思路了，首先向3 和 30 比较的话将3填充成33再和30比较大小。排序好整个数组。在直接将整个数组链接起来就行了。但是比较代码比较难写。最后受到Discuss的提醒。直接可以比较两个字符串链接起来的大小330和303的大小。


## 代码

````
type NumList []int

func (s NumList) Len() int { return len(s) }
func (s NumList) Less(i, j int) bool {
    return strconv.Itoa(s[i]) + strconv.Itoa(s[j]) > strconv.Itoa(s[j]) + strconv.Itoa(s[j])
}
func (s NumList) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func largestNumber(nums []int) string {
    sort.Sort(NumList(nums))
    var res string
    for _, value := range nums {
        res += strconv.Itoa(value)
    }
    
    if res[0] == '0' {
        res = "0"
    }
    
    return res
}

```
