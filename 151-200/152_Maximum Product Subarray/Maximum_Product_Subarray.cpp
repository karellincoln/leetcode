/**
 * 自己写的有错误的代码。没有处理好特殊的情况。
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = INT_MIN;
        int len = nums.size();
        int i = 0;
        while(true){
            // 去掉前置零。
            while (i < len && nums[i] == 0) {
                ++i;
                if(max < 0) max = 0;
            }
            if (i == len) break;

            int firstNegPro;
            int lastNegPro = 1;
            int current = 1;

            while(i < len && nums[i] > 0) current *= nums[i++];
            if(i == len) {
                if(current > max) max = current;
                break;
            }
            if(nums[i] == 0) {
                ++i;
                if(current > max) max = current;
                continue;
            }
            firstNegPro = current * nums[i];
            while(i < len && nums[i] != 0) current *= nums[i++];
            int j = i;
            while(lastNegPro > 0) lastNegPro *= nums[--j];

            int m = current;
            if (m < 0) m = (current/firstNegPro > current/lastNegPro) ? current/firstNegPro : current/lastNegPro;
            if (m == 1) m = current;
            max = (max > m) ? max : m;

            if (i == len) break;
        }

        return max;
    }
};


/**
 * dp 的解决方法。
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        vector<int> maxsub(nums.size());
        vector<int> minsub(nums.size());

        maxsub[0] = nums[0];
        minsub[0] = nums[0];

        for(int i = 1; i < nums.size(); ++i) {
            maxsub[i] = max(max(maxsub[i - 1] * nums[i], minsub[i - 1] * nums[i]), nums[i]);
            minsub[i] = min(min(maxsub[i - 1] * nums[i], minsub[i - 1] * nums[i]), nums[i]);

            result = max(result, maxsub[i]);
        }

        return result;
    }
};