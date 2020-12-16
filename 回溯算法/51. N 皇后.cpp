51. N 皇后

n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> pos(n, -1);
        dfs(ans, pos, 0);
        return ans;
    }
    void dfs(vector<vector<string>>& ans, vector<int>& pos, int row) {
        int n = pos.size();
        if (row == n) {
            vector<string> out(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                out[i][pos[i]] = 'Q';
            }
            ans.push_back(out);
        } else {
            for (int col = 0; col < n; ++col) {
                if (valid(pos, row, col)) {
                    pos[row] = col;
                    dfs(ans, pos, row + 1);
                    pos[row] = -1;
                }
            }
        }
    }
    bool valid(vector<int>& pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (i == row || col == pos[i] || abs(row - i) == abs(col - pos[i])) return false;
        }
        return true;
    }
};
