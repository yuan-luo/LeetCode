231. 2的幂

给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

如何获取二进制中最右边的1：x & (-x)
如何将二进制中最右边的1设置为0：x & (x - 1)

如果一个二进制数是由一个1和若干个0组成，它一定是一个2的幂次方。

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        long x = n;
        return (x & (x - 1)) == 0;
    }
};

方法二：
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        long x = n;
        return (x & (-x)) == x;
    }
 };
