343. 整数拆分

给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; ++i) {
            int curMax = 0;
            for (int j = 1; j < i; ++j) {
                curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curMax;
        }
        return dp.back();
    }
};
