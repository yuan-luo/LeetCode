205. 同构字符串

给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> m; // t -> s
        unordered_map<char, char> n; // s -> t
        for (int i = 0; i < s.size(); ++i) {
            if (n.count(s[i]) == 0 && m.count(t[i]) == 0) {
                n[s[i]] = t[i];
                m[t[i]] = s[i];
            } else {
                if (m[t[i]] != s[i]) return false;
            }
        }
        return true;
    }
};
