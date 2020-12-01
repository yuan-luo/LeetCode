560. 和为K的子数组

给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

题解分析：

这是一道非常经典的题目，思想用到了前缀和。用map记录累计和的次数。
如果存在sum[i] - sum[j] = k的话，说明j-i之间的累计和为k。sum为sum[i]，这样我们只需要考虑sum-k是否存在就可以了。

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> m; // sum -> times
        m[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ans += m[sum - k];
            ++m[sum];
        }
        return ans;
    }
};
