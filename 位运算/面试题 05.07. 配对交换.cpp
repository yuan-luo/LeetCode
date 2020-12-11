面试题 05.07. 配对交换

配对交换。编写程序，交换某个整数的奇数位和偶数位，尽量使用较少的指令（也就是说，位0与位1交换，位2与位3交换，以此类推）。

题解：

把偶数位置的数右移一位，把奇数位置的数左移一位，然后或起来。

class Solution {
public:
    int exchangeBits(int num) {
        int even = (num & 0xaaaaaaaa) >> 1;
        int odd = (num & 0x55555555) << 1;
        return even | odd;
    }
};
