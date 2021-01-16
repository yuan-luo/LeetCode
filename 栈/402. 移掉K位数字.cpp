402. 移掉K位数字

https://leetcode-cn.com/problems/remove-k-digits/

给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，
使得剩下的数字最小。

思路：

这道题要设计一个单调栈。每次插入新的数时和栈顶元素比较，
如果小于栈顶元素，就将栈顶元素退栈。最后再插入。
然后插入num.size()个元素，最后要保证退出k个元素。如果
之前没有退出这么多要从后面退出，因为后面的数大。
最后一个坑是要考虑去掉前缀0，有可能有很多个前缀0。

这里要注意它用的不是一个真正的stack，而是vector，因为打印
结果的时候要从头到尾打印。用vector方便遍历。

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for (auto& digit : num) {
            while (stk.size() > 0 && digit < stk.back() && k > 0) {
                --k;
                stk.pop_back();
            }
            stk.push_back(digit);
        }
        for (; k > 0; --k) stk.pop_back();
        string ans = "";
        bool isHeadZero = true;
        for (int i = 0; i < stk.size(); ++i) {
            if (isHeadZero && stk[i] == '0') continue;
            isHeadZero = false;
            ans += stk[i];
        }
        return ans == "" ? "0" : ans;
    }
};
