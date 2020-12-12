172. 阶乘后的零

https://leetcode-cn.com/problems/factorial-trailing-zeroes/

给定一个整数 n，返回 n! 结果尾数中零的数量。

思路：

其实就是看有多少个5的因子和2的因子。又因为每包含一个5的因子必然包含2的因子。所以只要查看有多少5的因子即可。

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n) {
            ans += n / 5;
            n /= 5;
        }
        return ans;
    }
};
