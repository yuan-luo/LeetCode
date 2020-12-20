461. 汉明距离

两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 x 和 y，计算它们之间的汉明距离。

class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y;
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            if (tmp & 1) ++ans;
            tmp >>= 1;
        }
        return ans;
    }
};
