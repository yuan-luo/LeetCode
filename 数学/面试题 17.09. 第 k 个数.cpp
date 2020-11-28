面试题 17.09. 第 k 个数

有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。

题解分析:

这道题是丑数II的变种题。需要注意的是要用long类型，不然会溢出。另外需要用一个set来记录结果。

class Solution {
public:
    int getKthMagicNumber(int k) {
        priority_queue<long, vector<long>, greater<long>> q;
        set<long> m;
        q.push(1);
        while (true) {
            long val = q.top(); q.pop();
            if (!m.count(val)) {
                m.insert(val);
                q.push(val * 3);
                q.push(val * 5);
                q.push(val * 7);
            }

            if (m.size() == k) return val;
        }
        return -1;
    }
};
