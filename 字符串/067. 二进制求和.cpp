67. 二进制求和

给你两个二进制字符串，返回它们的和（用二进制表示）。
输入为 非空 字符串且只包含数字 1 和 0。

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        string ans;
        while (m >= 0 || n >= 0) {
            int v1 = m >= 0 ? a[m--] - '0' : 0;
            int v2 = n >= 0 ? b[n--] - '0' : 0;
            int sum = v1 + v2 + carry;
            ans = to_string(sum % 2) + ans;
            carry = sum / 2;
        }
        if (carry > 0) ans = '1' + ans;
        return ans;
    }
};
