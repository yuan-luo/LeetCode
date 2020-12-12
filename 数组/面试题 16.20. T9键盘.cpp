面试题 16.20. T9键盘

在老式手机上，用户通过数字键盘输入，手机将提供与这些数字相匹配的单词列表。每个数字映射到0至4个字母。
给定一个数字序列，实现一个算法来返回匹配单词的列表。你会得到一张含有有效单词的列表。

思路：

首先用一个字符串数组存放每个按键的字母
第一个for循环取出words容器的单词，第二个for循环取出其中的字母
用zfc表示第几个按键的字符串，如果从for循环中取出的字母在该字符串中，count++
最后看count是否和words单词长度一样，若一样则表示每一个都存在zfc中，此时加入到vector中

链接：https://leetcode-cn.com/problems/t9-lcci/solution/20xing-csheng-nei-cun-jian-ma-by-logan-31/

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> svec;
        string letters[10] = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int count = 0;
        string zfc;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                zfc = letters[num[j] - '0'];
                if (zfc.find(words[i][j]) != zfc.npos) ++count;
            }
            if (count == words[i].size()) svec.push_back(words[i]);
            count = 0;
        }
        return svec;
    }
};

这道题我做了一个DFS版本，但是会TLE:
class Solution {
public:
    vector<string> ans;
    string out;
    unordered_map<char, string> m = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, 
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> getValidT9Words(string num, vector<string>& words) {
        unordered_set<string> dicts(words.begin(), words.end());
        string out;
        dfs(0, num, dicts);
        return ans;
    }
    void dfs(int index, string num, unordered_set<string>& dicts) {
        if (index == num.size() && dicts.count(out)) {
            ans.push_back(out);
            return;
        }
        for (int i = 0; i < m[num[index]].size(); ++i) {
            out.push_back(m[num[index]][i]);
            dfs(index + 1, num, dicts);
            out.pop_back();
        }
    }
};
