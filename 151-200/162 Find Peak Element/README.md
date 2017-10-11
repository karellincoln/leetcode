## 问题

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

**Note:**
Your solution should be in logarithmic complexity.

## 思考

问题还是比较简单的，一开始没有提示可以O(logn)的时候直接想到遍历数组，第一个下降的点就是了。  
提到O(logn)之后就是二分查找。


## 代码

```

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = (low + high) / 2;
            if(nums[mid] < nums[mid + 1]) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};

```
