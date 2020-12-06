面试题 16.07. 最大数值

编写一个方法，找出两个数字a和b中最大的那一个。不得使用if-else或其他比较运算符。

示例：

输入： a = 1, b = 2
输出： 2

class Solution {
public:
    int maximum(int a, int b) {
        long c = a;
        long d = b;
        return (long) (abs(c - d) + c + d) / 2;
    }
};
