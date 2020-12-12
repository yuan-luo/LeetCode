面试题 16.20. T9键盘

在老式手机上，用户通过数字键盘输入，手机将提供与这些数字相匹配的单词列表。每个数字映射到0至4个字母。
给定一个数字序列，实现一个算法来返回匹配单词的列表。你会得到一张含有有效单词的列表。映射如下图所示：

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
