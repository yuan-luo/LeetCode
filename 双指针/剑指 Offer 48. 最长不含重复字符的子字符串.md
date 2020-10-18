https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/

### 解题思路
用left指针表示左边界，如果字符子串出现重复left的字符，说明left左边包括left自己都可以被放弃掉。
这时候就需要把left标记为新的下标。（注意这个字符和left的字符其实是一样）
不管有没有重复字符，我们每次都记录m[s[i]]下来。

### 代码

```cpp
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
```
