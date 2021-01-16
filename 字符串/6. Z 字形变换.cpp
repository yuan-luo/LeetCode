6. Z 字形变换

将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

思路：

构造一个字符串数组，模拟打印过程依次把字母加到数组中去。
然后最后整理打印出来。

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        int n = s.length(), i = 0;
        string ans;
        vector<string> vec(numRows);
        while (i < n) {
            for (int pos = 0; pos < numRows && i < n; ++pos) {
                vec[pos] += s[i++];
            }
            for (int pos = numRows - 2; pos >= 1 && i < n; --pos) {
                vec[pos] += s[i++];
            }
        }
        for (auto& str : vec) ans += str;
        return ans;
    }
};
