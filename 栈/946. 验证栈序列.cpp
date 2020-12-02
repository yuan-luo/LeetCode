946. 验证栈序列

此题和剑指 Offer 31. 栈的压入、弹出序列雷同
https://leetcode-cn.com/problems/validate-stack-sequences/

给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。

示例 1：
输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true

题解:

模拟一个stack的真实插入删除过程。

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st; int popIndex = 0;
        for (int i = 0; i < pushed.size(); ++i) {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped[popIndex]) {
                st.pop();
                ++popIndex;
            }
        }
        return st.empty();
    }
};
