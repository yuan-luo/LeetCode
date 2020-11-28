面试题 08.11. 硬币

硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)

题解分析：

注意这道题和Coin Change的区别是它不是求最小分币数量，而是求有多少种解法。

注意循环顺序。比如 1+1+1+1+1+5 和 1+1+1+1+5+1 在Coin Change的算法中被重复计算，但在本题目中看做是一种。
换句话说本题目求组合数，而Coin Change是求排列数。

class Solution {
public:
    int waysToChange(int n) {
        vector<int> dp(n + 1, 0);
        vector<int> coins = {1, 5, 10, 25};
        dp[0] = 1;
        for (int j = 0; j < coins.size(); ++j) {
            for (int i = coins[j]; i <= n; ++i) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % 1000000007;
            }
        }
        return dp[n];
    }
};

时间复杂度：O(n)
空间复杂度：使用滚动数组思想优化后，只需要使用一个长度为 n + 1的一维数组，故渐进空间复杂度为 O(n)。
