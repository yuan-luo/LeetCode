91. 解码方法

一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

关键是看当前位置的数字能不能和前面的数字组成一种译码方式。
建立一维 dp 数组，其中 dp[i] 表示s中前i个字符组成的子串的解码方法的个数。
考虑不同情况：
1. dp[i] 至少和 dp[i - 1]一样多
2. 如果前面两位数<=26并且>=10，那么要加上dp[i - 2]

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = s[i - 1] == '0' ? 0 : dp[i - 1];
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
