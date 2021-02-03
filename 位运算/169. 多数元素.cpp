169. 多数元素

给定一个大小为 n 的数组，找到其中的多数元素。
多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int ones = 0, zeros = 0;
            for (int num : nums) {
                if (ones > n / 2 || zeros > n / 2) break;
                if ((num & (1 << i)) != 0) ++ones;
                else ++zeros;
            }
            if (ones > zeros) ans |= (1 << i);
        }
        return ans;
    }
};
