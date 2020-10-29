47. 全排列 II

https://leetcode-cn.com/problems/permutations-ii/

给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

注意：

求组合的时候要注意循环是从0开始。
注意剪枝条件 if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> out;
        sort(nums.begin(), nums.end());
        vector<int> visited(nums.size(), 0); // visited or not
        helper(nums, ans, out, visited, 0);
        return ans;
    }

    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& out, vector<int>& visited, int level) {
        if (level >= nums.size()) ans.push_back(out);
        else {
            for (int i = 0; i < nums.size(); ++i) {
                if (visited[i] == 0) {
                    if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
                    visited[i] = 1;
                    out.push_back(nums[i]);
                    helper(nums, ans, out, visited, level + 1);
                    out.pop_back();
                    visited[i] = 0;
                }
            }
        }
    }

};

