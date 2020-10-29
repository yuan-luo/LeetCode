90. 子集 II

给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> out;
        sort(nums.begin(), nums.end());
        helper(ans, out, nums, 0);
        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& out, vector<int>& nums, int level) {
        ans.push_back(out);
        for (int i = level; i < nums.size(); ++i) {
            out.push_back(nums[i]);
            helper(ans, out, nums, i + 1);
            out.pop_back();
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }
    }  
};
