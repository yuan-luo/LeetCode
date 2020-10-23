345. 反转字符串中的元音字母

https://leetcode-cn.com/problems/reverse-vowels-of-a-string/

编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isVowel(s[left])) ++left;
            while (left < right && !isVowel(s[right])) --right;
            swap(s[left], s[right]);
            ++left; --right;
        }
        return s;
    }

    bool isVowel(char c) {
        set<char> dict={'a','e','i','o','u','A','E','I','O','U'};
        if (dict.count(c)) return true;
        return false;
    }
};

