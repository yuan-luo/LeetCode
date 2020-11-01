260. 只出现一次的数字 III

给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

示例 :

输入: [1,2,1,3,2,5]
输出: [3,5]

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
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
