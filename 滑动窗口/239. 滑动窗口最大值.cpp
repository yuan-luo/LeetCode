239. 滑动窗口最大值

给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

示例 1：
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

思路：

设计一个deque存放滑动窗口，每当要加入当前数的时候把deque尾部不大于当前数的元素弹出。
当 i >= k - 1 时候把deque首部元素加入结果数组。

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (q.size() && i - q.front() >= k) q.pop_front();
            while (q.size() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
