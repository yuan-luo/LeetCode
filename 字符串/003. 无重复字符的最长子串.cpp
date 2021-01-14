3. 无重复字符的最长子串

https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

题解：

双指针解法
https://www.cnblogs.com/grandyang/p/4480780.html

这里解释下程序中那个 if 条件语句中的两个条件 m.count(s[i]) && m[s[i]] > left。
因为一旦当前字符 s[i] 在 HashMap 已经存在映射，说明当前的字符已经出现过了。
而若 m[s[i]] > left 成立，说明之前出现过的字符在窗口内。
那么如果要加上当前这个重复的字符，就要移除之前的那个，所以让 left 赋值为 m[s[i]]。

由于 left 是窗口左边界的前一个位置（这也是 left 初始化为 -1 的原因，因为窗口左边界是从0开始遍历的），
所以相当于已经移除出滑动窗口了。

举一个最简单的例子 "aa"，当 i=0 时，建立了 a->0 的映射，并且此时结果 res 更新为1，
那么当 i=1 的时候，发现a在 HashMap 中，并且映射值0大于 left 的 -1，所以此时 left 更新为0，
映射对更新为 a->1，那么此时 i-left 还为1，不用更新结果 res，那么最终结果 res 还为1。正确。

代码如下：

我的写法，left为0，如果冲突，left为m[s[i]]+1：
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m; //key -> index;
        int ans = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            //如果存在m[s[i]]
            if (m.count(s[i]) && m[s[i]] >= left) {
                left = m[s[i]] + 1;
            }
            m[s[i]] = i;
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int res = 0;
        int left = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (m.count(s[i]) && m[s[i]] > left) {
                left = m[s[i]];
            }
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};
