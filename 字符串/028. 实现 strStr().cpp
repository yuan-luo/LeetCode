28. 实现 strStr()

实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

=======================

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.size();
        int n = needle.size();
        if (m < n) return -1;
        
        for (int i = 0; i <= m - n; ++i) {
            int j = 0;
            for (j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (haystack.size() < needle.size()) return -1;
        int left = 0;
        for (int i = 0; i <= haystack.size() - needle.size(); ++i) { // 犯过错误：<=写成了<
            for (left = 0; left < needle.size(); ++left) { // 这里i指针不动的做法没有想出来。
                if (haystack[i + left] != needle[left]) break; 
            }
            if (left == needle.size()) return i; // 犯过错误：这里left是等于needle.size()而不是needle.size() - 1
        }
        return -1;
    }
};
