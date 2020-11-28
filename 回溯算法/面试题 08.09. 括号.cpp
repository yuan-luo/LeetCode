面试题 08.09. 括号

括号。设计一种算法，打印n对括号的所有合法的（例如，开闭一一对应）组合。

说明：解集不能包含重复的子集。

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, "", n, n);
        return ans;
    }

    void dfs(vector<string>& ans, string out, int left, int right) {
        if (left > right) return;
        if (left == 0 && right == 0) ans.push_back(out);
        else {
            if (left > 0) dfs(ans, out + '(', left - 1, right);
            if (right > 0) dfs(ans, out + ')', left, right - 1);
        }
    }
};
