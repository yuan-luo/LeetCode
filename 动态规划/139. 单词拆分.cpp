139. 单词拆分

给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，
判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

解题分析：

https://www.cnblogs.com/grandyang/p/4257740.html
用一个一维的 dp 数组，其中 dp[i] 表示范围 [0, i) 内的子串是否可以拆分。
注意这里 dp 数组的长度比s串的长度大1，是因为我们要 handle 空串的情况。
我们初始化 dp[0] 为 true，然后开始遍历。
注意这里我们需要两个 for 循环来遍历，因为此时已经没有递归函数了，所以我们必须要遍历所有的子串。
我们用j把 [0, i) 范围内的子串分为了两部分，[0, j) 和 [j, i)，
其中范围 [0, j) 就是 dp[j]，
范围 [j, i) 就是 s.substr(j, i-j)，其中 dp[j] 是之前的状态，我们已经算出来了，
可以直接取，只需要在字典中查找 s.substr(j, i-j) 是否存在了。
如果二者均为 true，将 dp[i] 赋为 true，并且 break 掉，此时就不需要再用j去分 [0, i) 范围了，
因为 [0, i) 范围已经可以拆分了。

最终我们返回 dp 数组的最后一个值，就是整个数组是否可以拆分的布尔值了，代码如下：

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {  
                // 注意这里s.substr(j, i - j)原因是
                // (i - 1) - j + 1 = i - j
                if (dp[j] && m.count(s.substr(j, i - j))) {
                    dp[i] = true;
                }
            }
        }    
        return dp.back();
    }
};
