557. 反转字符串中的单词 III

https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/

给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例：

输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"

解法一，利用STL iterator直接反转每个单词。

class Solution {
public:
    string reverseWords(string s) {
         auto start = s.begin();
         for (auto it = s.begin(); it != s.end(); ++it) {
             if (*it == ' ') {
                 reverse(start, it);
                 start = it + 1;
             }
         }
         reverse(start, s.end());
         return s;
    }
};

解法二，常规方法

class Solution {
public:
    string reverseWords(string s) {
         int storeIndex = 0;
         for (int i = 0; i < s.size(); ++i) {
             if (s[i] != ' ') {
                if (storeIndex != 0) s[storeIndex++] = ' ';
                int j = i;
                while (s[j] != ' ' && j < s.size()) s[storeIndex++] = s[j++];
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
             }
         }
         return s;
    }
};

