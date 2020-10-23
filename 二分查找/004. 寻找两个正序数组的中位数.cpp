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
        int k = (m + n + 1) / 2;

        // 在num1的区间[0, m]里面查找适当的分割线
        // 使得nums1[i - 1] <= nums2[j] 分割线在第一个数数组左边元素的数值要小于分割线在第二个数组右边的元素的数值，注意-1的表达表示在分割线的左边
        // && nums2[j - 1] <= nums1[i] 分割线在第二个数数组左边元素的数值要小于分割线在第一个数组右边的元素的数值，
        int left = 0;
        int right = m;
        while (left < right) {
            int m1 = left + (right - left) / 2;
            int m2 = k - m1;
            if (nums1[m1] < nums2[m2 - 1]) {
                // 下一轮的搜索区间[left, i - 1]
                left = m1 + 1;
            } else {
                // 下一轮的搜索区间[i, right]
                right = m1;
            }
        }

        int m1 = left;
        int m2 = k - left;
        int c1 = max(m1 <= 0 ? INT_MIN:nums1[m1 - 1],
                    m2 <= 0 ? INT_MIN:nums2[m2 - 1]);

        if ((m + n) % 2 == 1)
            return c1;
        int c2 = min(m1 >= m ? INT_MAX: nums1[m1],
                      m2 >= n ? INT_MAX : nums2[m2]);
        return (c1 + c2) * 0.5;
    }
};

