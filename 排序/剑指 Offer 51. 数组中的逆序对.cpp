剑指 Offer 51. 数组中的逆序对

class Solution {
public:
    int ans = 0;
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size(), 0);
        mergeSort(nums, 0, nums.size() - 1, tmp);
        return ans;
    }

    void mergeSort(vector<int>& nums, int left, int right, vector<int>& tmp) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, tmp);
        mergeSort(nums, mid + 1, right, tmp);
        merge(nums, left, mid, right, tmp);
    }

    void merge(vector<int>& nums, int left, int mid, int right, vector<int>& tmp) {
        int start1 = left;
        int start2 = mid + 1;
        int index = left;
        while (start1 <= mid && start2 <= right) {
            if (nums[start1] <= nums[start2]) {
                tmp[index++] = nums[start1++];
            } else {
                ans = mid - start1 + 1;
                tmp[index++] = nums[start2++];
            }
        }

        while (start1 <= mid) {
            tmp[index++] = nums[start1++];
        }
        
        while (start2 <= right) {
            tmp[index++] = nums[start2++];
        }

        for (int i = left; i <= right; ++i) nums[i] = tmp[i];
    }
};
