516. 最长回文子序列

给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。
可以假设 s 的最大长度为 1000 。

设置dp[i][j]为从i到j的字符串的最长回文子序列。
如果s[i] == s[j]，那么 dp[i][j] = dp[i + 1][j - 1] + 2
否则，为 max(dp[i][j - 1], dp[i + 1][j])

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        return dp[0][n - 1];
    }
};

