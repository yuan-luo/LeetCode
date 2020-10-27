剑指 Offer 56 - I. 数组中数字出现的次数

一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

a & (-a) 可以获得a最低的非0位 ,比如a的二进制是 ??????10000，取反就是??????01111，加1就是??????10000。前面?的部分是和原来a相反的，相与必然都是0，所以最后整体相与的结果就是00000010000。

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int xor_val = 0;
        // 把所有的元素进行异或操作
        for (int num : nums) {
            xor_val ^= num;
        }
        // 取异或值最后一个二进制位为 1 的数字作为 mask，如果是 1 则表示两个数字在这一位上不同
        int mask = xor_val & (-xor_val);
        vector<int> ans(2, 0);
        // 通过与这个 mask 进行与操作，如果为 0 的分为一个数组，为 1 的分为另一个数组。
        for (int num : nums) {
            if ((num & mask) == 0) {
                ans[0] ^= num;
            } else {
                ans[1] ^= num;
            }
        }
        return ans;
    }
};

