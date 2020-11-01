415. 字符串相加

给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int i = num1.size()- 1, j = num2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0) {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int tmp = n1 + n2 + carry;
            carry = tmp / 10;
            ans += to_string(tmp % 10);
            --i; --j;
        }
        if (carry) ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
