48. 旋转图像

给定一个 n × n 的二维矩阵表示一个图像。
将图像顺时针旋转 90 度。

示例 1:
给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
            }
        }
        reverse(matrix.begin(), matrix.end());
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[0].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
