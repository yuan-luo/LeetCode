240. 搜索二维矩阵 II

编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。

示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

给定 target = 5，返回 true。
给定 target = 20，返回 false。

解题思路：

从矩阵的右上方开始考虑，如果当前值小于target，向下走，
如果当前值大于target，向左走。

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int row = 0, col = matrix[0].size() - 1;
        while (row <= matrix.size() - 1 && col >= 0) {
            if (matrix[row][col] < target) ++row;
            else if (matrix[row][col] > target) --col;
            else return true;
        }
        return false;
    }
};
