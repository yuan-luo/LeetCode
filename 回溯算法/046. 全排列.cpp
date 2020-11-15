46. 全排列

给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> out;
        vector<int> visited(nums.size(), 0);
        helper(ans, out, nums, visited, 0);
        return ans;
    }

    void helper(vector<vector<int>>& ans, vector<int>& out, vector<int>& nums, vector<int>& visited, int level) {
        if (level == nums.size()) ans.push_back(out); // 错误：写成了==nums.size() - 1
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] == 0) {  // 错误： 没有考虑visited数组
                out.push_back(nums[i]);
                visited[i] = 1;
                helper(ans, out, nums, visited, level + 1); // 错误：用i+1，而不是level+1，说明没有理解清楚算法
                out.pop_back();
                visited[i] = 0; //错误：把最后三行放到了if条件作用域的外面
            }
        }
    }
};
