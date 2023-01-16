347. 前 K 个高频元素
https://leetcode-cn.com/problems/top-k-frequent-elements/
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

示例 2:
输入: nums = [1], k = 1
输出: [1]

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m; // val->freq;
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for (auto a : nums) ++m[a];
        for (auto it : m) q.push({it.second, it.first});
        for (int i = 0; i < k; ++i) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
