剑指 Offer 41. 数据流中的中位数

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
