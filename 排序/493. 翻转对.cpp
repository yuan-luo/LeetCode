493. 翻转对

给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。

你需要返回给定数组中的重要翻转对的数量。

解题思路：

这道题就是一道merge sort的变种题。先把数组对半拆成两个数组，然后分别递归merge sort处理。
i和j分别是两个数组的游标。 在处理结果的循环里面，当遇到nums[i] / 2.0 > nums[j]的时候，
说明j前面的数字都和nums[i]满足翻转对，所以++j，一轮循环下来满足的结果就是j - (mid + 1)。
下一轮循环j可以不用再初始化成mid + 1，可以节省时间。

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int res = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        for (int i = left, j = mid + 1; i <= mid; ++i) {
            while (j <= right && nums[i] / 2.0 > nums[j]) ++j;
            res += j - (mid + 1);
        }
        
        // 下面接下来要把两个排序数组真正merge排序，但如果写成STL的quick sort会超时。
        // 我个人觉得面试的时候可以直接写sort。
        // sort(nums.begin() + left, nums.begin() + right + 1);
        
        // 随后合并两个排序数组
        vector<int> sorted(right - left + 1);
        int p1 = left, p2 = mid + 1;
        int p = 0;
        while (p1 <= mid || p2 <= right) {
            if (p1 > mid) {
                sorted[p++] = nums[p2++];
            } else if (p2 > right) {
                sorted[p++] = nums[p1++];
            } else {
                if (nums[p1] < nums[p2]) {
                    sorted[p++] = nums[p1++];
                } else {
                    sorted[p++] = nums[p2++];
                }
            }
        }
        for (int i = 0; i < sorted.size(); i++) {
            nums[left + i] = sorted[i];
        }
        return res;
    }
};
