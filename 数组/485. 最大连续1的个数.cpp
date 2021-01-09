485. 最大连续1的个数

给定一个二进制数组， 计算其中最大连续1的个数。

示例 1:

输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int global = 0;
        int local = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) local++;
            if (nums[i] == 0) local = 0;
            if (local > global) global = local;
        }
        return global;
    }
};
