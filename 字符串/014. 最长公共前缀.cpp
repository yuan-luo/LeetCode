14. 最长公共前缀

输入: ["flower","flow","flight"]
输出: "fl"

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string res;
        char c;
        for (int j = 0; j < strs[0].size(); ++j) { // strs[0]的第j个字符
            char c = strs[0][j];
            for (int i = 1; i < strs.size(); ++i) { //strs[i]个字符串
                if (strs[i][j] != c) {
                    return res;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};
