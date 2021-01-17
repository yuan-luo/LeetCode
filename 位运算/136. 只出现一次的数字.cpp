136. 只出现一次的数字

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

题解：

这道题利用异或的性质：
任何数和 0 做异或运算，结果仍然是原来的数，即 a⊕0=a。
任何数和其自身做异或运算，结果是 0，即 a⊕a=0。
异或运算满足交换律和结合律，即 a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b。

所以我们把所有的数字进行异或这样的出来的就是那个只出现一次的数字。

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
};
