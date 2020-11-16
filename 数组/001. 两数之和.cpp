1. 两数之和

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; // val -> index
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(target - nums[i]) != m.end()) return {m[target - nums[i]], i};
            m[nums[i]] = i;
        }
        return {};
    }
};
