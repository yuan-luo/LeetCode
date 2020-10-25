219. 存在重复元素 II

https://leetcode-cn.com/problems/contains-duplicate-ii/

给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

======================================

这道题目设计一个hashmap，建立value到index的映射。
每轮循环对num[i]找map中是否存在，如果不存在，则把下标记录下来。
如果找到，检查它的下标和当前下标i是否相差k以内，如果找到返回成功，否则记录当前的nums[i]和下标i到map中。

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m; // value->location
        for (int i = 0; i < nums.size(); ++i) {
            if (!m.count(nums[i])) {
                m[nums[i]] = i;
            } else {
                if (abs(m[nums[i]] - i) <= k) return true;
                else m[nums[i]] = i;
            }
        }
        return false;
    }
};


