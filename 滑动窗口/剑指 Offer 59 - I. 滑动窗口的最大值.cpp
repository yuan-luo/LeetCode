剑指 Offer 59 - I. 滑动窗口的最大值

https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/

给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

本题的关键是设计一个deque，记录当前滑动窗口大小为K的从大到小的数。queue中的每一个数记录的是该数字在nums数组中的下标。
当queue头的数字下标滑出窗口范围的时候把它弹出。q.front() == i - k

任何一个数字进入deque之前，先把deque尾部小于自己的数字弹出，以保证deque中的数都大于自己。
这样deque头部就是滑动窗口最大数字。每次把dequeue头的数字加入结果。

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() == i - k) q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
