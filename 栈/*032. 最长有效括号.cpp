32. 最长有效括号

给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

解法一：

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') st.push(i);
            else {
                st.pop();
                if (st.empty()) st.push(i);
                else ans = max(ans, i - st.top());
            }
        }
        return ans;
    }
};

解法二：

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, start = 0;
        stack<int> m;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') m.push(i);
            if (s[i] == ')') {
                if (m.empty()) start = i + 1;
                else {
                    m.pop();
                    if (m.empty()) {
                        res = max(res, i - start + 1);
                    } else {
                        res = max(res, i - m.top());
                    }
                }
            }
        }
        return res;        
    }
};

