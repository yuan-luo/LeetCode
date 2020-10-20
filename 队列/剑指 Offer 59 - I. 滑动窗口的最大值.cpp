https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/

这个题目的解法就是构造一个单调递减双向队列deque来描述sliding window，
当deque记录的是当前数字的下标。当deque的队尾的数字小于nums[i]时，弹出队尾数字，直到不小于nums[i]再把i进入deque。
这时候能够保证deque里面一定是最大的k个数值。

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
