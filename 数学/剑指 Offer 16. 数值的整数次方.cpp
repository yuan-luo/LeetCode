剑指 Offer 16. 数值的整数次方

实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

很多细节需要考虑：
1. N需要是long long类型
2. quickPow()中，当N为0的时候要注意返回1.0

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n < 0) return 1.0 / quickPow(x, -(long long)n);
        return quickPow(x, (long long)n);
    }

    double quickPow(double x, long long N) {
        if (N == 0) return 1.0;
        double y = quickPow(x, N / 2);
        return (N % 2 == 0) ? y * y : y * y * x;
    }
};
