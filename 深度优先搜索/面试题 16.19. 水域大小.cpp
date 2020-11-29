面试题 16.19. 水域大小

你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。
若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。
编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。

解题思想：

这道题和200题岛屿数量很像，只不过它要打印出所有的值。我们需要用一个count值来记录当前区域池塘面积多大。

class Solution {
public:
    int count = 0;
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> ans;
        if (land.empty() || land[0].empty()) return ans;
        for (int y = 0; y < land.size(); ++y) {
            for (int x = 0; x < land[0].size(); ++x) {
                if (land[y][x] == 0) {
                    dfs(land, y, x);
                    if (count != 0) {
                        ans.push_back(count);
                        count = 0;
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    void dfs(vector<vector<int>>& land, int y, int x) {
        if (y < 0 || y > land.size() - 1 || x < 0 || x > land[0].size() - 1) return;
        if (land[y][x] == 0) {
            land[y][x] = -1;
            ++count;
        } else return;
        dfs(land, y - 1, x);
        dfs(land, y, x - 1);
        dfs(land, y + 1, x);
        dfs(land, y, x + 1);
        dfs(land, y - 1, x - 1);
        dfs(land, y - 1, x + 1);
        dfs(land, y + 1, x - 1);
        dfs(land, y + 1, x + 1);
    }
};
