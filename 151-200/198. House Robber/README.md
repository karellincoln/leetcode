## 198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and **it will automatically contact the police if two adjacent houses were broken into on the same night.**

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight **without alerting the police.**

## 思考

自己对这种状态的变化，步骤的思考不是很敏感。经常不能正确的想出具体的步骤。

## 代码

```

func rob(nums []int) int {
    max := func (a, b int) int {
        if a > b {
            return a
        }
        return b
    }
    rob, notrob := 0, 0
    for _, value := range nums {
        currob := notrob + value
        notrob = max(notrob, rob)
        rob = currob
    }
    
    return max(notrob, rob)
}

```
