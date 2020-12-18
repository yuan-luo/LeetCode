507. 完美数

对于一个 正整数，如果它和除了它自身以外的所有 正因子 之和相等，我们称它为 「完美数」。

给定一个 整数 n， 如果是完美数，返回 true，否则返回 false

思路：

对于n如果是平方数的话，那么我们此时相同的因子加来两次，所以我们要判断一下，如果相等，就不再加 num/i。

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 1;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0)
                sum += i + (num / i == i ? 0 : num / i);
        }
        return num != 1 && sum == num;
    }
};
