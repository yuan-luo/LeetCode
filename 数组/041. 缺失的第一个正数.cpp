41. 缺失的第一个正数

给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

示例 1:

输入: [1,2,0]
输出: 3

示例 2:

输入: [3,4,-1,1]
输出: 2

示例 3:

输入: [7,8,9,11,12]
输出: 1
 
提示：

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};
