207. 课程表

你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？

题解：

用BFS，定义二维数组 graph 来表示课程关系有向图，1->0说明先上1课程再上0课程。
数组in表示每门课程的入度。遍历课程时候每次到达一个节点把它的入度减一。如果某个课程入度为0则加入queue。
最后看如果有入度不为零则说明出现环。这道题其实就是deadlock detection的算法啊。

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in(numCourses);
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
            for (auto a : graph[t]) {
                --in[a];
                if (in[a] == 0) q.push(a);
            }
        }
        for (auto& a : in) {
            if (a != 0) return false;
        }
        return true;
    }
};
