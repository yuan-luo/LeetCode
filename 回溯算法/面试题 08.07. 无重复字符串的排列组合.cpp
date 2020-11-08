面试题 08.07. 无重复字符串的排列组合

无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。

示例1:

 输入：S = "qwe"
 输出：["qwe", "qew", "wqe", "weq", "ewq", "eqw"]

示例2:

 输入：S = "ab"
 输出：["ab", "ba"]

class Solution {
public:
    vector<string> permutation(string S) {
        vector<string> ans;
        string out;
        vector<int> visited(S.size(), 0);
        helper(ans, out, S, visited, 0);
        return ans;
    }

    void helper(vector<string>& ans, string& out, string& S, vector<int>& visited, int depth) {
        if (depth == S.size()) ans.push_back(out);
        for (int i = 0; i < S.size(); ++i) {
            if (visited[i] == 0) {
                out.push_back(S[i]);
                visited[i] = 1;
                helper(ans, out, S, visited, depth + 1);
                out.pop_back();
                visited[i] = 0;
            }
        }
    }
};
