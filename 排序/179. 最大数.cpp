179. 最大数

给定一组非负整数 nums，重新排列它们每位数字的顺序使之组成一个最大的整数。
注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。

示例 1：
输入：nums = [10,2]
输出："210"

示例 2：
输入：nums = [3,30,34,5,9]
输出："9534330"

示例 3：
输入：nums = [1]
输出："1"

示例 4：
输入：nums = [10]
输出："10"

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s;
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });

        for (int i = 0; i < nums.size(); ++i) {
            s += to_string(nums[i]);
        }

        if (s[0] == '0') return "0";
        return s;
    }
};
