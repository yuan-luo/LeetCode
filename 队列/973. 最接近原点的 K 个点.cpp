973. 最接近原点的 K 个点

我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。
（这里，平面上两点之间的距离是欧几里德距离。）
你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < K; ++i) {
            q.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
        }
        for (int i = K; i < points.size(); ++i) {
            q.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
            q.pop();
        }
        vector<vector<int>> ans;
        for (int i = 0; i < K; ++i) {
            ans.push_back({points[q.top().second][0], points[q.top().second][1]});
            q.pop();
        }
        return ans;
    }
};
