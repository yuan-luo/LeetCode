1004. 最大连续1的个数 III

给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。

返回仅包含 1 的最长（连续）子数组的长度。

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, zero = 0, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) ++zero;
            while (zero > k) {
                if (nums[left++] == 0) --zero;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
