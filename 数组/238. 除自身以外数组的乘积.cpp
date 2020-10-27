给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]

构建正反两个数组记录左边数字的乘积和以及右边数字的乘积和。
然后构造一个数组把左边乘积乘以右边乘积。
注意初始化的时候把左右两侧的数字初始化成1。

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> forward(n, 1);
        vector<int> backward(n, 1);
        vector<int> ans;

        for (int i = 0; i < n - 1; ++i) {
            forward[i + 1] = nums[i] * forward[i];
        }
        for (int i = n - 1; i > 0; --i) {
            backward[i - 1] = nums[i] * backward[i];
        }

        for (int i = 0; i < nums.size(); ++i) {
            ans.push_back(forward[i] * backward[i]);
        }
        return ans;
    }
};
