221. 最大正方形

在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

示例：

输入：
matrix = [["1","0","1","0","0"],
          ["1","0","1","1","1"],
          ["1","1","1","1","1"],
          ["1","0","0","1","0"]]

输出：4

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            sz = max(sz, dp[i][0]);
        }

        for (int j = 0; j < n; ++j) { 
            dp[0][j] = matrix[0][j] - '0';
            sz = max(sz, dp[0][j]);
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    sz = max(sz, dp[i][j]);                    
                }
            }
        }
        return sz * sz;
    }
};
