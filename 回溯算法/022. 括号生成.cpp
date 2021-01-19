22. 括号生成

数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例：

输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
       
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string out;
        dfs(ans, out, n, n);
        return ans;
    }
    void dfs(vector<string>& ans, string& out, int left, int right) {
        if (left > right || left < 0 || right < 0) return;
        if (left == 0 && right == 0) {
            ans.push_back(out);    
            return;
        }
        else {
            out.push_back('(');
            dfs(ans, out, left - 1, right);
            out.pop_back();
            out.push_back(')');
            dfs(ans, out, left, right - 1);
            out.pop_back();
        }      
    }
};

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
