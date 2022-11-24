76. 最小覆盖子串

给你一个字符串 S、一个字符串 T 。
请你设计一种算法，可以在 O(n) 的时间复杂度内，
从字符串 S 里面找出：包含 T 所有字符的最小子串。

示例：
输入：S = "ADOBECODEBANC", T = "ABC"
输出："BANC"

参考自：
https://www.cnblogs.com/grandyang/p/4340948.html

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        int cnt = 0, left = 0;
        int minLen = INT_MAX;
        string ans = "";
        for (auto c : t) m[c]++;
        for (int i = 0; i < s.size(); ++i) {
            if (--m[s[i]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    ans = s.substr(left, minLen);
                }
                if (++m[s[left]] > 0) --cnt;
                ++left;
            }
        }
        return ans;
    }
};

这道题和第3题有相似的地方。
https://github.com/yuan-luo/LeetCode/blob/master/%E5%AD%97%E7%AC%A6%E4%B8%B2/003.%20%E6%97%A0%E9%87%8D%E5%A4%8D%E5%AD%97%E7%AC%A6%E7%9A%84%E6%9C%80%E9%95%BF%E5%AD%90%E4%B8%B2.cpp
第3题的map的value是保存字符的下标。而这道题value是保存字符出现的次数。
如果字符出现一次就减1，如过value大于等于0则说明hit了字符串 t 中的字符。
当left右移时，每次把字符加1，如果大于0说明hit了字符串t中的字符。
因为如果不在t中的话，value会等于0，因为之前扫描到的时候减了1。
