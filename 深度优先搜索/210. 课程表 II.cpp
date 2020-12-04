210. 课程表 II

现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。

可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。

题解：

这道题比207题课程表复杂在需要把一个解集返回。
我们在每次遍历的时候记录下来。如果最后ans的大小不等于课程总数则返回空，否则返回结果。

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        for (auto& a : prerequisites) {
            graph[a[1]].push_back(a[0]);
            ++in[a[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) q.push(i); 
        }
        while (!q.empty()) {
            int t = q.front(); q.pop();
            ans.push_back(t);
            for (auto& a : graph[t]) {
                --in[a];
                if (in[a] == 0) q.push(a);
            }
        }
        if (ans.size() != numCourses) ans.clear();
        return ans;
    }
};
