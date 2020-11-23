54. 螺旋矩阵

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0, right = matrix[0].size() - 1;
        int up = 0, down = matrix.size() - 1;
        while (true) {
            for (int j = left; j <= right; ++j) ans.push_back(matrix[up][j]);
            if (++up > down) break;
            for (int i = up; i <= down; ++i) ans.push_back(matrix[i][right]);
            if (--right < left) break;
            for (int j = right; j >= left; --j) ans.push_back(matrix[down][j]);
            if (--down < up) break;
            for (int i = down; i >= up; --i) ans.push_back(matrix[i][left]);
            if (++left > right) break;  
        }
        return ans;
    }
};

