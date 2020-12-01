34. 在排序数组中查找元素的第一个和最后一个位置

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/14699/Clean-iterative-solution-with-two-binary-searches-(with-explanation)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int idxLeft = searchTargetIndex(nums, target, true);

        if (idxLeft == nums.size() || nums[idxLeft] != target) return res;

        int idxRight = searchTargetIndex(nums, target, false);
        res[0] = idxLeft;
        res[1] = idxRight - 1;
        return res;
    }

    int searchTargetIndex(vector<int>& nums, int target, bool left) {
        int lo = 0;
        int hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target || (left && nums[mid] == target)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};

解法二：（推荐）

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1, -1};
        if (nums.size() == 0) return ans;
        int left = 0, right = nums.size() - 1;
        if (target < nums[left] || target > nums[right]) return {-1, -1};

        // 找左边界
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else right = mid; // 向左逼近
        }
        if (nums[left] != target) ans[0] = -1;
        else ans[0] = left;

        // 找右边界
        left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2; // 注意这里mid要加1/2，因为要考虑往右边靠近
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid; // 向右逼近
        }
        if (nums[left] != target) ans[1] = -1;
        else ans[1] = right;

        return ans;
    }
};







