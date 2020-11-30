面试题 17.22. 单词转换

给定字典中的两个词，长度相等。写一个方法，把一个词转换成另一个词， 但是一次只能改变一个字符。每一步得到的新词都必须能在字典中找到。

编写一个程序，返回一个可能的转换序列。如有多个可能的转换序列，你可以返回任何一个。

示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
["hit","hot","dot","lot","log","cog"]

class Solution {
public:
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for (const auto& word : wordList) unset.insert(word);
        vector<string> ans{beginWord};
        if (dfs(beginWord, endWord, ans)) return ans;
        return {};
    }

    bool dfs(string& begin, const string& end, vector<string>& ans) {
        if (begin == end) return true;
        for (auto& ch : begin) {
            char c = ch;
            for (char i = 'a'; i <= 'z'; ++i) {
                if (i == c) continue;
                ch = i;
                if (unset.count(begin) && !visited.count(begin)) {
                    visited.insert(begin);
                    ans.push_back(begin);
                    if (dfs(begin, end, ans)) return true;
                    ans.pop_back();
                }
            }
            ch = c;
        }
        return false;
    }
private:
    unordered_set<string> unset;
    unordered_set<string> visited;
};
