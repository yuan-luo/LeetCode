213. 打家劫舍 II

你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

题解：

设置两个数组，将nums的头尾去掉，分别进行独立计算。

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> v1 = nums;
        vector<int> v2 = nums;
        v1.erase(v1.begin());
        v2.pop_back();
        return max(helper(v1), helper(v2));
    }

    int helper(vector<int>& nums) {
        int ans;
        int size = nums.size();
        if (size == 0) return 0;
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        if (size == 1) return dp[0];

        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp.back();
    }    
};
