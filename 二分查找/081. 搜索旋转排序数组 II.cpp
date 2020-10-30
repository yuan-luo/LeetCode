81. 搜索旋转排序数组 II

https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
示例 2:

输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
进阶:

这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

题解：

这道题最关键的就是当nums[mid] == nums[high]的时候把high--.
这也是和之前那道搜索旋转排序数组题目的唯一区别的地方。

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return true;
            
            if (nums[mid] > nums[high]) {
                if(nums[mid] > target && nums[low] <= target) high = mid - 1;
                else low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                if (nums[mid] < target && nums[high] >= target) low = mid + 1;
                else high = mid - 1;
            } else {
                high-- ;
            }
        }
        return false;
    }
};
