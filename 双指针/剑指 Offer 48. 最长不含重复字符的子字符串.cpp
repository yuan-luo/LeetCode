https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/

### 解题思路

解释下程序中那个 if 条件语句中的两个条件 m.count(s[i]) && m[s[i]] > left，
因为一旦当前字符 s[i] 在 HashMap 已经存在映射，说明当前的字符已经出现过了，而若 m[s[i]] > left 成立，
说明之前出现过的字符在窗口内，那么如果要加上当前这个重复的字符，就要移除之前的那个，
所以让 left 赋值为 m[s[i]]，由于 left 是窗口左边界的前一个位置
（这也是 left 初始化为 -1 的原因，因为窗口左边界是从0开始遍历的），所以相当于已经移除出滑动窗口了。

用left指针表示左边界，如果字符子串出现重复left的字符，说明left左边包括left自己都可以被放弃掉。
这时候就需要把left标记为新的下标。（注意这个字符和left的字符其实是一样）
不管有没有重复字符，我们每次都记录m[s[i]]下来。

### 代码

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int res = 0, left = -1, n = s.size();
        unordered_map<int, int> m; // 字符:下标
        for (int i = 0; i < n; ++i) {
            if (m.count(s[i]) && m[s[i]] > left) {
                left = m[s[i]];  // m[s[i]]表示字符为s[i]的下标
            }
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};

