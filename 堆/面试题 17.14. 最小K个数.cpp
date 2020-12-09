面试题 17.14. 最小K个数

设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。

题解：

找最小的K个数要建立一个大小为K的大顶堆，因为每次pop出去的数都比这个大顶堆中的任意一个数要大。
所以最后得到大顶堆中就是最小的K个数。
顺便复习一下priority_queued的API：
top(), push(), emplace(), pop(), size(), empty()

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, less<int>> q;
        vector<int> ans;
        for (int i = 0; i < arr.size(); ++i) {
            q.push(arr[i]);
            if (q.size() > k) q.pop();
        }
        for (int i = 0; i < k; ++i) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans; 
    }
};
