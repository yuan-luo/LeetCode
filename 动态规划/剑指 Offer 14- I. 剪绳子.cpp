剑指 Offer 14- I. 剪绳子

给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

解题思路：

这道题其实没用动态规划做。注意一下如果小于零的话，要把最小值和最大值交换一下。

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int minProd = 1;
        int maxProd = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) swap(minProd, maxProd);
            minProd = min(nums[i], minProd * nums[i]);
            maxProd = max(nums[i], maxProd * nums[i]);
            ans = max(ans, maxProd);
        }
        return ans;
    }
};
