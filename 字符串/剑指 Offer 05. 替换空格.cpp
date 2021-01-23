剑指 Offer 05. 替换空格

请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0, len = s.size();
        for (auto c : s) {
            if (c == ' ') ++cnt;
        }
        s.resize(len + cnt * 2);
        for (int i = len - 1, j = s.size() - 1; i >= 0; --i, --j) {
            if (s[i] != ' ') s[j] = s[i]; 
            else {
                s[j - 2] = '%'; s[j - 1] = '2'; s[j] = '0';
                j -= 2;
            }
        }
        return s;
    }
};
