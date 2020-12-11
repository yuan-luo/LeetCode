面试题 17.04. 消失的数字

数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？

题解：

把所有数字和0到n异或一下，最后的出来的数字就是缺失的整数。

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ans ^= (i + 1) ^ nums[i];
        }
        return ans;
    }
};
