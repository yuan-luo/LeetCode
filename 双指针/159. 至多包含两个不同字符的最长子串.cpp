159. 至多包含两个不同字符的最长子串

给定一个字符串 s ，找出 至多 包含两个不同字符的最长子串 t ，并返回该子串的长度。

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans = 0, left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            m[s[i]]++;
            while (m.size() > 2) {
                if (--m[s[left]] == 0) m.erase(s[left]);
                ++left;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
