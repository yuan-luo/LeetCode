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

解法一：

首先把第一个区间存入结果中，然后从第二个开始遍历区间集，
如果结果中最后一个区间和遍历的当前区间无重叠，直接将当前区间存入结果中，
如果有重叠，将结果中最后一个区间的 end 值更新为结果中最后一个区间的 end 
和当前 end 值之中的较大值，然后继续遍历区间集，以此类推可以得到最终结果。

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans({intervals[0]});
        for (int i = 1; i < intervals.size(); ++i) {
            if (ans.back()[1] < intervals[i][0]) ans.push_back(intervals[i]);
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};


解法二：

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
