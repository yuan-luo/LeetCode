面试题 05.06. 整数转换

整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。

思路：

先异或，再统计1的个数。

class Solution {
public:
    int convertInteger(int A, int B) {
        int ans = 0;
        unsigned int n = A ^ B; 
        while (n != 0) {
            n = n & (n - 1);
            ++ans;
        }
        return ans;
    }
};
