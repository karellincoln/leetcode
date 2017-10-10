class Solution {
public:
    int help(vector<int> &nums, int s, int e) {
        if(s == e || nums[s] < nums[e]) return nums[s];

        int mid = (s + e) >> 1;
        if(mid ==s || nums[mid] > nums[s]) return help(nums, mid + 1, e);
        return help(nums, s, mid);
    }
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        return help(nums, 0, nums.size() - 1);
    }
};