78. 子集

给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

注意：

求排列的时候循环下标从level开始，并且helper(ans, out, nums, i + 1)，这里我曾经做错成level + 1。
另外结果输出的时候不需要level==nums.size() - 1。

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
        }
    }
};
