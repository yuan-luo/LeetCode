56. 合并区间

给出一个区间的集合，请合并所有重叠的区间。 

示例 1:

输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: intervals = [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

题解：
 
这道题隐含条件就是左边已经排序，所以只需要考虑区间右界的值。
设t为待处理区间的右边界，j为新区间的index。把每个区间的结果加到merge里面。
 
class Solution {

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        vector<vector<int>> merge;
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size();) { // 注意在这里循环不需要++i，因为i会由j来递进。
            int t = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t) {
                t = max(t, intervals[j][1]);
                ++j;
            }
            merge.push_back({intervals[i][0], t});
            i = j;
        }

        return merge;
    }
};
