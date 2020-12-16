290. 单词规律

给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true

题解：

设置两个map，value为下标加1.
这里需要加1就是为了避免默认映射值0，因为 C++ 中的 HashMap 的机制是若访问一个不存在的 key 值，会默认建立一个映射值为0的映射。
那么我们在遇到新字符和单词时，首先看 i 是否已经是 n 了，若相等了，说明此时 pattern 中的字符已经用完了。
而 str 中还有多余的单词，这样是无法建立一对一映射的，直接返回 false。

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> char_map; // char -> index + 1
        unordered_map<string, int> word_map; // word -> index + 1
        istringstream in(s);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || char_map[pattern[i]] != word_map[word]) return false;
            char_map[pattern[i]] = word_map[word] = i + 1;
        }
        return i == n;
    }
};

