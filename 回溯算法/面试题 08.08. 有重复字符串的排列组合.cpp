面试题 08.08. 有重复字符串的排列组合

有重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合。

示例1:

 输入：S = "qqe"
 输出：["eqq","qeq","qqe"]

示例2:

 输入：S = "ab"
 输出：["ab", "ba"]

class Solution {
public:
    vector<string> ans;
    string out;
    
    vector<string> permutation(string S) {
        if (S.empty()) return ans;
        vector<int> visited(S.size(), 0);
        sort(S.begin(), S.end());
        helper(S, visited, 0);
        return ans;
    }

    void helper(string S, vector<int>& visited, int depth) {
        if (depth == S.size()) {
            ans.push_back(out);
            return;
        }
        for (int i = 0; i < S.size(); ++i) {
            if (visited[i]) continue;
            if (i > 0 && S[i] == S[i - 1] && visited[i - 1] == 0) continue;
            out.push_back(S[i]);
            visited[i] = 1;
            helper(S, visited, depth + 1);
            out.pop_back();
            visited[i] = 0;
        }
    }
};
