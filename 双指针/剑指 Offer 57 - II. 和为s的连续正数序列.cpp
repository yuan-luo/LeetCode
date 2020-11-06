剑指 Offer 57 - II. 和为s的连续正数序列

输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

示例 1：
输入：target = 9
输出：[[2,3,4],[4,5]]

示例 2：
输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]

解题思路：

设置双指针 l 和 r，初始值分别从1 和 2 开始，通过数学方法计算sum值，然后sum值和target大小关系分下面三种情况讨论：
1. sum == target：找到满足条件的[l, r]，加入结果集；
2. sum < target：则移动右指针
3. sum > target：则移动左指针
终止条件为 l >= r，这种情况只有当r 移到 target / 2 + 1位置时，导致l < r 的时候区间大于target，移动l 使两者相等。

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1, right = 2;
        vector<vector<int>> ans;

        while (left < right) {
            vector<int> out;
            int sum = (left + right) * (right - left + 1) / 2;
            if (sum == target) {
                // 输出这一组结果
                for (int i = left; i <= right; ++i) out.push_back(i);
                ans.push_back(out);
                ++left;
            } else if (sum < target) {
                ++right;
            } else {
                ++left;
            }
        }
        return ans;
    }
};
