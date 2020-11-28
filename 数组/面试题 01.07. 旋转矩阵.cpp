面试题 01.07. 旋转矩阵

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            for (int i = j; i < matrix.size(); ++i) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
