
给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，
其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。
每个 Ai 或 Bi 是一个表示单个变量的字符串。

另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，
请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。

返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。
如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替代这个答案。

注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，
且不存在任何矛盾的结果。


方法一：广度优先搜索
我们可以将整个问题建模成一张图：给定图中的一些点（变量），
以及某些边的权值（两个变量的比值），
试对任意两点（两个变量）求出其路径长（两个变量的比值）。

因此，我们首先需要遍历 equations 数组，
找出其中所有不同的字符串，并通过哈希表将每个不同的字符串映射成整数。

在构建完图之后，对于任何一个查询，就可以从起点出发，
通过广度优先搜索的方式，不断更新起点与当前点之间的路径长度，
直到搜索到终点为止。


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int nvars = 0;
        unordered_map<string, int> variables;
        
        int n = equations.size();
        for (int i = 0; i < n; ++i) {
            if (variables.find(equations[i][0]) == variables.end()) {
                variables[equations[i][0]] = nvars++;
            }
            if (variables.find(equations[i][1]) == variables.end()) {
                variables[equations[i][1]] = nvars++;
            }
        }
        
        // 对于每个点，存储其直接连接到的所有点及对应的权值
        vector<vector<pair<int, double>>> edges(nvars);
        for (int i = 0; i < n; ++i) {
            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
            edges[va].push_back(make_pair(vb, values[i]));
            edges[vb].push_back(make_pair(va, 1.0 / values[i]));
        }

        vector<double> ret;
        for (const auto& q: queries) {
            double result = -1.0;
            if (variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end()) {
                int ia = variables[q[0]], ib = variables[q[1]];
                if (ia == ib) {
                    result = 1.0;
                } else {
                    queue<int> points;
                    points.push(ia);
                    vector<double> ratios(nvars, -1.0);
                    ratios[ia] = 1.0;
                    
                    while (!points.empty() && ratios[ib] < 0) {
                        int x = points.front();
                        points.pop();
                        for (const auto [y, val]: edges[x]) {
                            if (ratios[y] < 0) {
                                ratios[y] = ratios[x] * val;
                                points.push(y);
                            }
                        }
                    }
                    result = ratios[ib];
                }
            }
            ret.push_back(result);
        }
        return ret;
    }
};
