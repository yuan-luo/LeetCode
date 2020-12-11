面试题 17.16. 按摩师

一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。
在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

题解：

这道题其实就是打家劫舍。

class Solution {
public:
    int massage(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp.back();
    }
};
