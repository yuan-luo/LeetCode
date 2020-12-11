剑指 Offer 65. 不用加减乘除做加法

class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {
            int carry = (unsigned int) (a & b) << 1; // carry是进位
            a = a ^ b; // 非进位和
            b = carry; 
        }
        return a;
    }
};  
