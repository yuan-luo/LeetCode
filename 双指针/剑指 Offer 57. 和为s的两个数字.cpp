剑指 Offer 57. 和为s的两个数字

输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int sum = 0;
        while (right > left) {
            if (nums[left] + nums[right] == target) return vector<int>{nums[left], nums[right]};
            else if (nums[left] + nums[right] < target) ++left;
            else --right;
        }
        return {0, 0};
    }
};
