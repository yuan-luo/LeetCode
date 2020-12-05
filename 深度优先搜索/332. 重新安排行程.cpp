332. 重新安排行程

给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。
所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。

示例 1：

输入：[["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
输出：["JFK", "MUC", "LHR", "SFO", "SJC"]

题解：

First keep going forward until you get stuck. That's a good main path already. 
Remaining tickets form cycles which are found on the way back and get merged into that main path. 
By writing down the path backwards when retreating from recursion, merging the cycles into the main path is easy - 
the end part of the path has already been written, the start part of the path hasn't been written yet, 
so just write down the cycle now and then keep backwards-writing the path.

class Solution {
public:
    map<string, multiset<string>> targets;
    vector<string> route;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket : tickets)
            targets[ticket[0]].insert(ticket[1]);
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }
    void visit(string airport) {
        while (targets[airport].size()) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }
        route.push_back(airport);
    }
};
