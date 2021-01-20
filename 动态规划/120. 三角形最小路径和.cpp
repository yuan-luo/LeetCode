120. 三角形最小路径和

给定一个三角形 triangle ，找出自顶向下的最小路径和。

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m - 1].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = triangle[0][0]; 
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                } else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                }
                cout << i << " " << j << "     " << dp[i][j] << endl;
            }
        }
        for (int j = 0; j < n; ++j) {
            ans = min(ans, dp[m - 1][j]);
        }
        return ans;
    }
};
