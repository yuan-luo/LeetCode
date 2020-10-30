347. 前 K 个高频元素

给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m; // val:freq;
        vector<int> res;
        priority_queue<pair<int, int>> q;
        for (auto i : nums) {
            m[i]++;
        }
        for (auto it : m) {
            q.push(pair<int, int>(it.second, it.first));
        }
        for (int i = 0; i < k; ++i) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
