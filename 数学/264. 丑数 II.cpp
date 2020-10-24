264. 丑数 II

https://leetcode-cn.com/problems/ugly-number-ii/

编写一个程序，找出第 n 个丑数。

丑数就是质因数只包含 2, 3, 5 的正整数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。

====================================
题解：

The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).

题解来自于隐藏提示。说明下一个丑数是来自于三个list中的最大值。
我们建一个小顶堆，每次都插入这三个list的值，并且弹出重复的元素，这样n轮循环以后，顶堆的元素就是第n大的丑数。
值得注意的是：这里的小顶堆的size不一定是n，它表达的意思是经过了n轮循环迭代，产生了n次三个list中的最小值的选择，最后选择出来的第n大的丑数。

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

