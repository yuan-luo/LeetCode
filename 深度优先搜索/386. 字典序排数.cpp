386. 字典序排数

给定一个整数 n, 返回从 1 到 n 的字典顺序。

例如，

给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。

请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。

class Solution {
    vector<int> ans;
public:
    vector<int> lexicalOrder(int n) {
        for (int i = 1; i < 10; ++i) {
            dfs(n, i);
        }
        return ans;
    }

    void dfs(int n, int cur) {
        if (cur > n) return;
        ans.push_back(cur);
        for (int i = 0; i < 10; ++i) {
            dfs(n, cur * 10 + i);
        }
    }
};
