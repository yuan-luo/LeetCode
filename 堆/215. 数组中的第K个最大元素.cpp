215. 数组中的第K个最大元素

https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            else if (pos > k - 1) {
                right = pos - 1;
            } else {
                left = pos + 1;
            }
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivotal = nums[right];
        while (left < right) {
            while (left < right && nums[left] >= pivotal) ++left;
            swap(nums[left], nums[right]);
            while (left < right && nums[right] <= pivotal) --right;
            swap(nums[left], nums[right]);
        }
        return right;
    }
        
};
