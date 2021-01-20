567. 字符串的排列

给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
换句话说，第一个字符串的排列之一是第二个字符串的子串。

用一个滑动窗口和双指针。用一个hashmap记录s1出现的次数。
如果m[s2[right]]>0出现就cnt--并自减一。
遇到cnt==0，收集结果。left不断往右移动，闭关把m[s2[left]]加一。
如果m[s2[left]]>0那么++cnt，说明s1中有字母被移出了滑动窗口。

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0, ans = 0, cnt = s1.size();
        unordered_map<char, int> m; // char -> freq
        for (char c : s1) m[c]++;
        for (int right = 0; right < s2.size(); ++right) {
            if (m[s2[right]]-- > 0) --cnt; 
            while (cnt == 0) {
                if (right - left + 1 == s1.size()) return true;
                if (++m[s2[left]] > 0) {
                    ++cnt;
                }
                ++left;
            }
        }
        return false;
    }
};
