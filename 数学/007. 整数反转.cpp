7. 整数反转

给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

class Solution {
public:
    int reverse(int x) {
        if (x / 10 == 0) return x;
        int y = 0;
        while (x) {
            if (y > INT_MAX / 10 || y < INT_MIN / 10) return 0;
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }
};
