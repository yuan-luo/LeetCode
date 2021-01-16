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

具体做法是我们始终保持栈底元素为当前已经遍历过的元素中
「最后一个没有被匹配的右括号的下标」，这样的做法主要是考虑了边界条件的处理，
栈里其他元素维护左括号的下标：

对于遇到的每个‘(’，我们将它的下标放入栈中
对于遇到的每个‘)’，我们先弹出栈顶元素表示匹配了当前右括号：
如果栈为空，说明当前的右括号为没有被匹配的右括号，
我们将其下标放入栈中来更新我们之前提到的「最后一个没有被匹配的右括号的下标」
如果栈不为空，当前右括号的下标减去栈顶元素即为
「以该右括号为结尾的最长有效括号的长度」
我们从前往后遍历字符串并更新答案即可。

需要注意的是，如果一开始栈为空，第一个字符为左括号的时候我们会将其放入栈中，
这样就不满足提及的「最后一个没有被匹配的右括号的下标」，
为了保持统一，我们在一开始的时候往栈中放入一个值为-1的元素。

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

解法三：
先把左括号入栈，然后遇到有右括号的时候看有没有左括号，如果有就出栈，
如果没有说明栈为空或者栈里还有右括号，这时候把这个不匹配的右括号进栈。
进栈是记录坐标，而不是括号本身。
循环一轮如果栈为空说明全部匹配，长度为n。如果不为空说明有不匹配的
左括号或者右括号。这时候把任何两个栈中的括号之间的最大距离计算出来
就能得到最大的匹配长度。注意要考虑两个边界情况也要记录在内。
a为右边，b为左边。走到最后a就是最后一个元素，也要参与计算。

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size(), ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push(i);
            else { // s[i] == ')'
                if (!st.empty()) {
                    if (s[st.top()] == '(') st.pop();
                    else st.push(i);
                } else st.push(i);
            }
        }
        if (st.empty()) return n;
        int a = n, b = 0;
        while (!st.empty()) {
            b = st.top(); 
            st.pop();
            ans = max(ans, a - b - 1);
            a = b;
        }
        ans = max(ans, a);
        return ans;
    }
};

