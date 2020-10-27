191. 位1的个数

编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。

题解：

n & (n - 1)运算每次能够移除n最右边的1。

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            ++ans;
            n = n & (n - 1);
        }
        return ans;
    }
};
