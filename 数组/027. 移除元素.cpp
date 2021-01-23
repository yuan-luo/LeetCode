27. 移除元素

给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，
并返回移除后数组的新长度。

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) nums[slow++] = nums[i];
        }
        return slow;
    }
};
