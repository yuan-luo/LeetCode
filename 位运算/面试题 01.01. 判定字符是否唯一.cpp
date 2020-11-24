面试题 01.01. 判定字符是否唯一

实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

class Solution {
public:
    bool isUnique(string astr) {
        int x = 0;
        for (auto c : astr) {
            if (x & 1 << (c - 'a')) return false;
            else x |= 1 << (c - 'a');
        }
        return true;
    }
};
