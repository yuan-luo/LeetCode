剑指 Offer 13. 机器人的运动范围

地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
也不能进入行坐标和列坐标的数位之和大于k的格子。

例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

class Solution {
public:
    int digit_sum(int i) {
        int sum = 0;
        while (i != 0) {
            sum += i % 10;
            i /= 10;
        }
        return sum;
    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        return dfsSolver(0, 0, m, n, k, visited);
    }

    int dfsSolver(int i, int j, int m, int n, int k, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= m || j >= n
            || (digit_sum(i) + digit_sum(j)) > k
            || visited[i][j] == true) {
                return 0;
            }
        visited[i][j] = true;
        return 1 + dfsSolver(i + 1, j, m, n, k, visited)
                 + dfsSolver(i - 1, j, m, n, k, visited)
                 + dfsSolver(i, j + 1, m, n, k, visited)
                 + dfsSolver(i, j - 1, m, n, k, visited);
    }
};
