912. 排序数组

给你一个整数数组 nums，请你将该数组升序排列。

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quicksort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = partition(nums, left, right);
            quicksort(nums, left, mid - 1);
            quicksort(nums, mid + 1, right);
        }
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivotal = nums[right];
        while (left < right) {
            while (left < right && nums[left] <= pivotal) ++left;
            swap(nums[left], nums[right]);
            while (left < right && nums[right] >= pivotal) --right;
            swap(nums[left], nums[right]);
        }
        return right;
    }
};
