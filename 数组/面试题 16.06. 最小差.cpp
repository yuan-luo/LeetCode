面试题 16.06. 最小差

给定两个整数数组a和b，计算具有最小差绝对值的一对数值（每个数组中取一个值），并返回该对数值的差。

题解分析：

先分别排序，在利用双指针逼夹比较。

class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long ans = INT_MAX;
        for (int i = 0, j = 0; i < a.size() && j < b.size();) {
            ans = min(ans, abs((long)a[i] - (long)b[j]));
            if (a[i] > b[j]) ++j;
            else ++i;
        }
        return ans;
    }
};
