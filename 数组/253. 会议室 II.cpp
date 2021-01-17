253. 会议室 II

给你一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间
intervals[i] = [starti, endi] ，为避免会议冲突，同时要考虑充分利用会议室资源，
请你计算至少需要多少间会议室，才能满足这些会议安排。

构造一个最小堆，把会议的结束时间进堆，如果当前堆顶的结束时间比要进堆会议的开始
时间小，那么直接退出堆顶元素，说明不需要加会议室。然后把当前会议结束时间入堆。

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < intervals.size(); ++i) {
            if (!q.empty() && q.top() <= intervals[i][0]) q.pop();
            q.push(intervals[i][1]);
        }
        return q.size();
    }
};
