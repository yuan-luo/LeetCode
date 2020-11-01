137. 只出现一次的数字 II

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            // 统计每位二进制数出现1的次数，将次数mod3应该为0。不为零的部分就为结果数字。
            for (int j = 0; j < nums.size(); ++j) {
                sum += (nums[j] >> i) & 1;
            }
            ans |= (sum % 3) << i;
        }
        return ans;
    }
};
