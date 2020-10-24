剑指 Offer 17. 打印从1到最大的n位数

输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]

======================================================
dfs算法

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        string str;
        str.resize(n);
        printNumbers(n, 0, str, res);
        return res;
    }

    void printNumbers(int n, int index, string &str, vector<int> &res) {
        if (index == n) {
            int num = atoi(str.c_str());
            if (num != 0) res.push_back(num);
            return;
        }
        for (int i = 0; i <= 9; ++i) {
            str[index] = i + '0';
            printNumbers(n, index + 1, str, res);
        }
    }
};
