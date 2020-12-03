74. 搜索二维矩阵

编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。

输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
[1, 3, 5, 7],
[10,11,16,20],
[23,30,34,50]
输出：true

输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
输出：false

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int pivotVal = matrix[mid / n][mid % n];
            if (pivotVal == target) return true;
            else if (pivotVal < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};

比较240题，如果不能保证每行的头比上一行的尾要小，那么解法如下：

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
