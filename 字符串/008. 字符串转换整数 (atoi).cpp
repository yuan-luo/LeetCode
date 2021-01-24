8. 字符串转换整数 (atoi)

请你来实现一个 atoi 函数，使其能将字符串转换成整数。
在任何情况下，若函数不能进行有效的转换时，请返回 0 。

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        while (s[i] == ' ') ++i;
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '+') ? 1 : -1;
            ++i;
        }
        long num = 0;
        while (s[i] <= '9' && s[i] >= '0' && i < s.size()) {
            num = num * 10 + s[i] - '0';
            if (num * sign >= INT_MAX) return INT_MAX;
            else if (num * sign <= INT_MIN) return INT_MIN;
            ++i;
        }
        return num * sign;
    }
};
