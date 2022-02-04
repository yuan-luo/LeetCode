85. 最大矩形

给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int res = 0;
        vector<int> height;
        for (int i = 0; i < matrix.size(); ++i) {
            height.resize(matrix[i].size());
            for (int j = 0; j < matrix[i].size(); ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }

    int largestRectangleArea(vector<int>& height) {
        int res = 0;
        stack<int> stk;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            if (stk.empty() || height[stk.top()] <= height[i]) {
                stk.push(i);
            } else {
                int tmp = stk.top(); stk.pop();
                res = max(res, height[tmp] *(stk.empty() ? i : (i - stk.top() - 1)));
                --i;
            }
        }
        return res;
    }
};
