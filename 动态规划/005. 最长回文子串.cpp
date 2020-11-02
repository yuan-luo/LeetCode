5. 最长回文子串

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

题解：

维护一个二维数组 dp，其中 dp[j][i] 表示字符串区间 [j, i] 是否为回文串，
当 j = i 时，只有一个字符，肯定是回文串，如果 i = j + 1，说明是相邻字符，
此时需要判断 s[j] 是否等于 s[i]，
如果i和j不相邻，即 i - j >= 2 时，除了判断 s[i] 和 s[j] 相等之外，
dp[j + 1][i - 1] 若为真，就是回文串，通过以上分析，可以写出递推式如下：

dp[j, i]   = 1                                   if i == j
           = s[i] == s[j]                        if i = j + 1
           = s[i] == s[j] && dp[j + 1][i - 1]    if i > j + 1
           
注意j是回文子串的左下标，i是回文子串的右下标。

class Solution {
public:
    string longestPalindrome(string s) {
        int len = 1;
        int left = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
            for (int j = 0; j < i; ++j) {
                if (s[j] == s[i] && (dp[j + 1][i - 1] == 1 || i - j < 2)) {
                    dp[j][i] = 1;
                    if (i - j + 1 > len) {
                        len = i - j + 1;
                        left = j;
                    } 
                }
            }
        }
        return s.substr(left, len);
    }
};

