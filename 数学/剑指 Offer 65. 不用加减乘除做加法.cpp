剑指 Offer 65. 不用加减乘除做加法

class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {
            int c = (unsigned int) (a & b) << 1; // c是进位
            a = a ^ b; // 非进位和
            b = c; 
        }
        return a;
    }
};
