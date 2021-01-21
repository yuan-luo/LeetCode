面试题 08.03. 魔术索引

魔术索引。 在数组A[0...n-1]中，有所谓的魔术索引，满足条件A[i] = i。
给定一个有序整数数组，编写一种方法找出魔术索引，
若有的话，在数组A中找出一个魔术索引，如果没有，则返回-1。
若有多个魔术索引，返回索引值最小的一个。

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        return bsearch(nums, 0, nums.size() - 1);
    }

    int bsearch(vector<int>& nums, int left, int right) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        left = bsearch(nums, left, mid - 1);
        if (left != -1) return left;
        if (mid == nums[mid]) return mid;
        else return bsearch(nums, mid + 1, right);
    }
};
