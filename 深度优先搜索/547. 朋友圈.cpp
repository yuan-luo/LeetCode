547. 朋友圈

班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。
如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。
所谓的朋友圈，是指所有朋友的集合。

给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。
如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。
你必须输出所有学生中的已知的朋友圈总数。

示例 1：
输入：
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出：2 

解释：已知学生 0 和学生 1 互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回 2 。

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            helper(isConnected, i, visited);
            ++ans;
        }
        return ans;
    }
    void helper(vector<vector<int>>& isConnected, int k, vector<bool>& visited) {
        visited[k] = true;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (visited[i] == false && isConnected[k][i]) {
                helper(isConnected, i, visited);
            }
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), ans = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            helper(M, i, visited);
            ++ans;
        }
        return ans;
    }
    void helper(vector<vector<int>>& M, int k, vector<bool>& visited) {
        visited[k] = true;
        for (int i = 0; i < M.size(); ++i) {
            if (!M[k][i] || visited[i]) continue;
            helper(M, i, visited);
        }
    }
};
