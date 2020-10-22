352. 将数据流变为多个不相交区间

给定一个非负整数的数据流输入 a1，a2，…，an，…，将到目前为止看到的数字总结为不相交的区间列表。

例如，假设数据流中的整数为 1，3，7，2，6，…，每次的总结为：

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]

进阶：
如果有很多合并，并且与数据流的大小相比，不相交区间的数量很小，该怎么办?

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }
    
    void addNum(int val) {
        vector<int> newInterval{val, val};
        vector<vector<int>> res;
        int cur = 0;
        for (auto interval : intervals) {
            // 1. 新的区间比当前区间小，且不重合，加入当前区间到结果
            if (interval[0] > newInterval[1] + 1) {
                res.push_back(interval);
            } else if (interval[1] + 1 < newInterval[0]) {
            // 2. 新的区间比当前区间大，且不重合，加入当前区间到结果，并增加下标，因为以后newInterval要加到那个下标的位置。
                res.push_back(interval);
                cur++;
            } else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }
        
        res.insert(res.begin() + cur, newInterval);
        intervals = res;
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }

private:
    vector<vector<int>> intervals;
};
