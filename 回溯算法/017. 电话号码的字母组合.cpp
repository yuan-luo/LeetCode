17. 电话号码的字母组合

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

class Solution {
public:
    vector<string> ans;
    string out;
    unordered_map<char, string> m = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, 
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return ans;
        dfs(0, digits);
        return ans;
    }

    // DFS函数，index是生成临时结果字串的下标，
    // 每一个digits[index]数字对应临时结果current[index]的一位字母
    void dfs(int index, string digits) {
        if (index == digits.size()) {
            ans.push_back(out);
            return;
        }
        //递归调用
        //对于当前输入的第index号数字(digits[index])，
        //枚举其对应的所有字母(M[digits[index]][i])
        for (int i = 0; i < m[digits[index]].size(); ++i) {
            out.push_back(m[digits[index]][i]);
            dfs(index + 1, digits);
            out.pop_back();
        }
    }
};

