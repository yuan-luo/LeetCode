面试题 16.24. 数对和

设计一个算法，找出数组中两数之和为指定值的所有整数对。一个数只能属于一个数对。

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(target - nums[i]) && m[target - nums[i]] > 0) {
                m[target - nums[i]]--;
                ans.push_back({target - nums[i], nums[i]});
            } else {
                m[nums[i]]++;
            }
        }
        return ans;
    }
};
