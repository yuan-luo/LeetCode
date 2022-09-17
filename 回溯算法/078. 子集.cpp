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

下面这个方案感觉更清晰，更直观。cur代表当前要加入的待选数组。
当n==cur.size()，说明当前已经找到一个答案，加入到ans中。
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        for(int i = 0; i <= nums.size(); ++i) {
            dfs(nums, i, 0, cur, ans);    
        }
        return ans;
    }
    void dfs(const vector<int>& nums, int n, int s, vector<int> cur, vector<vector<int>>& ans) {
        if (n == cur.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = s; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(nums, n, i + 1, cur, ans);
            cur.pop_back();
        }
    }

};
