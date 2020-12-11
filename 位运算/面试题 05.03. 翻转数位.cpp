面试题 05.03. 翻转数位

给定一个32位整数 num，你可以将一个数位从0变为1。请编写一个程序，找出你能够获得的最长的一串1的长度。

题解：

统计前一段连续的 1 的个数，以及后一段连续 1 的个数，两者之和 +1 就是翻转一个 0->1 后连续 1 的个数。
坑：注意一定要把num转成unsigned int n，因为num可能是负数。

class Solution {
public:
    int reverseBits(int num) {
        int pre = 0, cur = 0;
        if (num == -1) return 32;
        int ans = 0;
        unsigned int n = num;
        while (n) {
            if (n & 1) {
                ++cur;
            } else {
                pre = cur;
                cur = 0;
            }
            ans = max(ans, pre + cur);
            n = n >> 1;
        }
        return ans + 1;
    }
};
