052. N皇后 II

n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给定一个整数 n，返回 n 皇后不同的解决方案的数量。

class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> pos(n, -1);
        dfs(ans, pos, 0);
        return ans.size();
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
