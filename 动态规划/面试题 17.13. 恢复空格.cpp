面试题 17.13. 恢复空格

哦，不！你不小心把一个长篇文章中的空格、标点都删掉了，并且大写也弄成了小写。
像句子"I reset the computer. It still didn’t boot!"已经变成了"iresetthecomputeritstilldidntboot"。
在处理标点符号和大小写之前，你得先把它断成词语。当然了，你有一本厚厚的词典dictionary，不过，有些词没在词典里。
假设文章用sentence表示，设计一个算法，把文章断开，要求未识别的字符最少，返回未识别的字符数。

题解:

设dp[i]为以i下标结尾的最长识别字符数。这样dp[i]就等于dp[i]和以i结尾，并且单词在字典里的dp[i-word.length()]值加上单词长度的比较值中的较大值。
参考： https://www.bilibili.com/video/BV1Wt4y1Q7Qa?from=search&seid=10413680160379847676

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        vector<int> dp(sentence.length() + 1, 0);
        int right = 1;
        while (right <= sentence.length()) {
            dp[right] = dp[right - 1];
            for (string word : dictionary) {
                if (right < word.length()) continue;
                string tmp = sentence.substr(right - word.length(), word.length());
                if (tmp == word) dp[right] = max(dp[right], (int)(dp[right - word.length()] + word.length()));
            }
            ++right;
        }
        return sentence.length() - dp.back();
    }
};
