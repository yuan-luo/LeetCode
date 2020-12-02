224. 基本计算器

实现一个基本的计算器来计算一个简单的字符串表达式的值。
字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。

示例:
输入: "(1+(4+5+2)-3)+(6+8)"
输出: 23

class Solution {
public:
    int calculate(string s) {
        stack<int> stk, ops;
        int num = 0;
        char sign = 1;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) num = num * 10 + (c - '0');
            else {
                ans += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    stk.push(ans);
                    ops.push(sign);
                    ans = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    ans = ops.top() * ans + stk.top();
                    ops.pop(); stk.pop();
                }
            }
        }
        ans += sign * num;
        return ans;
    }
};
