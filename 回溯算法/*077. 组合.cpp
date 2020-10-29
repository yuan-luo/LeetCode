77. 组合

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

题解：

k即depth用来控制结果长度。

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> out;
        vector<vector<int>> res;
        helper(n, res, out, 1, k);
        return res;
    }
    
    void helper(int n, vector<vector<int>>& res, vector<int>& out, int level, int depth) {
        if (out.size() == depth) res.push_back(out);
        for (int i = level; i <= n; ++i) {
            out.push_back(i);
            helper(n, res, out, i + 1, depth);
            out.pop_back();
        }
        
    }
};
