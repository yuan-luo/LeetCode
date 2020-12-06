119. 杨辉三角 II

给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

题解：

除了第一个和最后一个数字之外，其他的数字都是上一行左右两个值之和。
那么我们只需要两个 for 循环，除了第一个数为1之外，后面的数都是上一次循环的数值加上它前面位置的数值之和，
不停地更新每一个位置的值，便可以得到第n行的数字。

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j >= 1; --j) {
                ans[j] += ans[j - 1];
            }
        }
        return ans;
    }
};
