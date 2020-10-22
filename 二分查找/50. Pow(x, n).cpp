实现 pow(x, n) ，即计算 x 的 n 次幂函数。

题解：

n次方 = n为偶数，可分成n/2取整次方的平方。n为奇数，分成n/2取整次方的平方 * n
n连续/2，到达边界，
1次方 = 数本身，
0次方 = 1

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickPow(x, N) : 1.0 / quickPow(x, -N);
    }

    double quickPow(double x, long long N) {
        if (N == 0)
            return 1.0;
        double y = quickPow(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }
};



