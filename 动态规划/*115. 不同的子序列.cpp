115. 不同的子序列

给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。

字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

题目数据保证答案符合 32 位带符号整数范围。

题解分析：

Solution (DP):
We keep a m*n matrix and scanning through string S, while
m = T.length() + 1 and n = S.length() + 1
and each cell in matrix Path[i][j] means the number of distinct subsequences of 
T.substr(1...i) in S(1...j)

dp[i][j] = dp[i][j-1]            (discard S[j])
             +     dp[i-1][j-1]    (S[j] == T[i] and we are going to use S[j])
                or 0                 (S[j] != T[i] so we could not use S[j])
while dp[0][j] = 1 and dp[i][0] = 0.

另外一种解释方式：
https://leetcode.com/problems/distinct-subsequences/discuss/37316/7-10-lines-C%2B%2B-Solutions-with-Detailed-Explanations-(O(m*n)-time-and-O(m)-space)

Well, a dynamic programming problem. 
Let's first define its state dp[i][j] to be the number of distinct subsequences of t[0..i - 1] in s[0..j - 1]. 
Then we have the following state equations:

General case 1: dp[i][j] = dp[i][j - 1] if t[i - 1] != s[j - 1];
General case 2: dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] if t[i - 1] == s[j - 1];
Boundary case 1: dp[0][j] = 1 for all j;
Boundary case 2: dp[i][0] = 0 for all positive i.
Now let's give brief explanations to the four equations above.

If t[i - 1] != s[j - 1], the distinct subsequences will not include s[j - 1] and thus all the number of distinct subsequences will simply be those in s[0..j - 2], which corresponds to dp[i][j - 1];
If t[i - 1] == s[j - 1], the number of distinct subsequences include two parts: those with s[j - 1] and those without;
An empty string will have exactly one subsequence in any string.
Non-empty string will have no subsequences in an empty string.  
  
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length();
        int n = s.length();
        if (m > n) return 0; // impossible for subsequence
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        for (int k = 0; k <= n; ++k) dp[0][k] = 1;
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= m; ++i) {
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp.back().back();
    }
};

