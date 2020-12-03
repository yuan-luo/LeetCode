面试题 01.08. 零矩阵

编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

算法：

原地置零。先处理边界第0行和第0列，如果有0，那么先记录下来flag。
接下来处理每一位如果有零那么把边界置零。
接下来循环每一位如果行或者列边界有零那么把这一位置零。
接下来检查之前的flag，如果有设置的把边界这一行或者列置零。

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroRow = false, zeroCol = false;
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        for (int i = 0; i < matrix.size(); ++i) 
            if(matrix[i][0] == 0) zeroRow = true;
        for (int i = 0; i < matrix[0].size(); ++i) 
            if(matrix[0][i] == 0) zeroCol = true;
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i) 
            if (zeroRow == true) matrix[i][0] = 0;
        for (int i = 0; i < matrix[0].size(); ++i) 
            if(zeroCol == true)  matrix[0][i] = 0;          
    }
};
