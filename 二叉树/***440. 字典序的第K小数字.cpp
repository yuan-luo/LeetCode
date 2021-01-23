440. 字典序的第K小数字

给定整数 n 和 k，找到 1 到 n 中字典序第 k 小的数字。

解释:
字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，
所以第二小的数字是 10。

解题思路：

这道题太精妙了。构造一个十叉树。
//https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
//discuss/92242/ConciseEasy-to-understand-Java-5ms-solution-with-Explaination
Actually this is a denary tree (each node has 10 children). 
Find the kth element is to do a k steps preorder traverse of the tree.

找K小的数字其实就是遍历查找这个十叉树的过程。具体看题解。

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k;
        while (k > 0) {
            long long step = 0, first = cur, last = cur + 1;
            while (first <= n) {
                step += min((long long)n + 1, last) - first;
                first *= 10;
                last *= 10;
            }
            if (step <= k) {
                ++cur;
                k -= step;
            } else {
                cur *= 10;
                --k;
            }
        }
        return cur;
    }
};
