96. 不同的二叉搜索树

给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

题解：

动态规划。以i为root的节点组成的二叉搜索树的种数是左子树乘以右子树的个数。
dp[i - 1] * dp[n - i]
然后把所有节点为root的情况累加一下。

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i - 1; ++j) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp.back();
    }
};
