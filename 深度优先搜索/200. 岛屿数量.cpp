200. 岛屿数量

给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

示例 1：
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1

示例 2：
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        if (grid.empty() || grid[0].empty()) return 0;
        for (int y = 0; y < grid.size(); ++y) {
            for (int x = 0; x < grid[0].size(); ++x) {
                ans += grid[y][x] - '0';
                dfs(grid, y, x);
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int y, int x) {
        if (y < 0 || y > grid.size() - 1 || x < 0 || x > grid[0].size() - 1 || grid[y][x] == '0') return;
        grid[y][x] = '0';
        dfs(grid, y - 1, x);
        dfs(grid, y + 1, x);
        dfs(grid, y, x - 1);
        dfs(grid, y, x + 1);
    }
};
