152. 乘积最大子数组

给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

题解：

当nums[i]<0的时候，前面的最小值乘以nums[i]反而成了最大值，所以最小值也要记录下来。

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int imax = 1, imin = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) swap(imax, imin);
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            ans = max(ans, imax);
        }
        return ans;
    }
};
