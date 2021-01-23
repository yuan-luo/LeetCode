26. 删除排序数组中的重复项

给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int slow = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[slow]) {
                nums[++slow] = nums[i];
            }
        }
        return slow + 1;
    }
};
