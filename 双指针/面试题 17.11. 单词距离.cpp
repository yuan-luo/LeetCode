面试题 17.11. 单词距离

有个内含单词的超大文本文件，给定任意两个单词，
找出在这个文件中这两个单词的最短距离(相隔单词数)。
如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?

示例：

输入：words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
    
输出：1

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int t1 = -1, t2 = -1, ans = words.size();
        for (int i = 0; i < words.size(); ++i) {
            if (word1 == words[i]) t1 = i;
            else if (word2 == words[i]) t2 = i;
            if (t1 != -1 && t2 != -1) ans = min(ans, abs(t1 - t2));
            if (ans == 1) break;
        }
        return ans;
    }
};
