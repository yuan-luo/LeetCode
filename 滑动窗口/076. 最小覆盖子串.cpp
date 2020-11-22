76. 最小覆盖子串

给你一个字符串 S、一个字符串 T 。请你设计一种算法，可以在 O(n) 的时间复杂度内，从字符串 S 里面找出：包含 T 所有字符的最小子串。

示例：
输入：S = "ADOBECODEBANC", T = "ABC"
输出："BANC"

题解分析：

参考自：
https://www.cnblogs.com/grandyang/p/4340948.html

下面来考虑用代码来实现，先来回答一下前面埋下的伏笔，为啥要用 HashMap，而不是 HashSet，
现在应该很显而易见了吧，因为要统计T串中字母的个数，而不是仅仅看某个字母是否在T串中出现。
统计好T串中字母的个数了之后，开始遍历S串，对于S中的每个遍历到的字母，都在 HashMap 中的映射值减1，
如果减1后的映射值仍大于等于0，说明当前遍历到的字母是T串中的字母，使用一个计数器 cnt，使其自增1。
当 cnt 和T串字母个数相等时，说明此时的窗口已经包含了T串中的所有字母，此时更新一个 minLen 和结果 res，
这里的 minLen 是一个全局变量，用来记录出现过的包含T串所有字母的最短的子串的长度，结果 res 就是这个最短的子串。
然后开始收缩左边界，由于遍历的时候，对映射值减了1，所以此时去除字母的时候，就要把减去的1加回来，此时如果加1后的值大于0了，
说明此时少了一个T中的字母，那么 cnt 值就要减1了，然后移动左边界 left。
你可能会疑问，对于不在T串中的字母的映射值也这么加呀减呀的，真的没事吗？
其实没啥事，因为对于不在T串中的字母，减1后，变-1，cnt 不会增加，之后收缩左边界的时候，
映射值加1后为0，cnt 也不会减少，所以并没有什么影响啦，
下面是具体的步骤啦：

- 先扫描一遍T，把对应的字符及其出现的次数存到 HashMap 中。
- 然后开始遍历S，就把遍历到的字母对应的 HashMap 中的 value 减一，如果减1后仍大于等于0，cnt 自增1。
- 如果 cnt 等于T串长度时，开始循环，纪录一个字串并更新最小字串值。然后将子窗口的左边界向右移，如果某个移除掉的字母是T串中不可缺少的字母，那么 cnt 自减1，表示此时T串并没有完全匹配。  
  
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        int cnt = 0, left = 0;
        int minLen = INT_MAX;
        string ans = "";
        for (auto c : t) m[c]++;
        for (int i = 0; i < s.size(); ++i) {
            if (--m[s[i]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    ans = s.substr(left, minLen);
                }
                if (++m[s[left]] > 0) --cnt;
                ++left;
            }
        }
        return ans;
    }
};


这道题和第3题有相似的地方。
https://github.com/yuan-luo/LeetCode/blob/master/%E5%AD%97%E7%AC%A6%E4%B8%B2/003.%20%E6%97%A0%E9%87%8D%E5%A4%8D%E5%AD%97%E7%AC%A6%E7%9A%84%E6%9C%80%E9%95%BF%E5%AD%90%E4%B8%B2.cpp

3. 无重复字符的最长子串
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。






