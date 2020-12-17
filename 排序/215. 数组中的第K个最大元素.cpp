215. 数组中的第K个最大元素

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
