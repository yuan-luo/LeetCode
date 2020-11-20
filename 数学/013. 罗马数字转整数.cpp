13. 罗马数字转整数

题解：

当右边字符代表的数字小于等于当前字符代表的数字的时候，要把当前字符代表的数值加到总和里面，否则就从总和里面减去。

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i == s.size() - 1 || m[s[i + 1]] <= m[s[i]]) ans += m[s[i]];
            else ans -= m[s[i]];
        }
        return ans;
    }
};
