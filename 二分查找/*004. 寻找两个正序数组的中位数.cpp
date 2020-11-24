4. 寻找两个正序数组的中位数

给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。

进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();

        // 分割线左边的所有元素需要满足的个数(m + n + 1)/2
        int totalLeft = (m + n + 1) / 2;

        // 在num1的区间[0, m]里面查找适当的分割线
        int left = 0;
        int right = m;

        while (left < right) {
            int i = left + (right - left) / 2;
            int j = totalLeft - i;
            if (nums1[i] < nums2[j - 1]) {
                left = i + 1;
            } else {
                right = i;
            }
        }

        int i = left;
        int j = totalLeft - i;
        int nums1LeftMax = (i <= 0) ? INT_MIN : nums1[i - 1];
        int nums1RightMin = (i >= m) ? INT_MAX : nums1[i];
        int nums2LeftMax = (j <= 0) ? INT_MIN : nums2[j - 1];
        int nums2RightMin = (j >= n) ? INT_MAX : nums2[j];
     
        if ((m + n) % 2 == 1)
            return max(nums1LeftMax, nums2LeftMax);

        else
            return (double) (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) * 0.5;
    }
}; 

另外一种类似解法：
============================================================
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0;
        int right = m;
        // median1：前一部分的最大值
        // median2：后一部分的最小值
        int median1 = 0;
        int median2 = 0;

        while (left <= right) {
            // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
            // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
            int left_part1 = (i == 0 ? INT_MIN : nums1[i - 1]);
            int right_part1 = (i == m ? INT_MAX : nums1[i]);
            int left_part2 = (j == 0 ? INT_MIN : nums2[j - 1]);
            int right_part2 = (j == n ? INT_MAX : nums2[j]);

            if (left_part1 <= right_part2) {
                median1 = max(left_part1, left_part2);
                median2 = min(right_part1, right_part2);
                left = i + 1;
            }
            else {
                right = i - 1;
            }
        }

        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
};
