43. 字符串相乘

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        // 结果最多为m + n位数
        vector<int> ans(m + n, 0);
        // 从个位数开始逐位相乘
        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + ans[p2];
                ans[p2] = sum % 10;
                ans[p1] += sum / 10;
            }
        // 结果前缀可能存的0（未使用的位）
        int i = 0;
        while (i < ans.size() && ans[i] == 0) ++i;
        // 将计算结果转化为字符串
        string str;
        for (; i < ans.size(); ++i) str.push_back('0' + ans[i]);
        return str.size() == 0 ? "0" : str;
    }
};
