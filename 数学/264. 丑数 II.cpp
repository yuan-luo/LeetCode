264. 丑数 II

https://leetcode-cn.com/problems/ugly-number-ii/

编写一个程序，找出第 n 个丑数。

丑数就是质因数只包含 2, 3, 5 的正整数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。

====================================

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<double, vector<double>, greater<double>> q;
        double ans = 1;
        for (int i = 1; i < n; ++i) {
            q.push(2 * ans);
            q.push(3 * ans);
            q.push(5 * ans);
            ans = q.top();
            q.pop();
            while (!q.empty() && q.top() == ans) q.pop(); 
        }
        return ans;
    }
};

