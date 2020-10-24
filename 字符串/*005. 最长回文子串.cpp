5. 最长回文子串

https://leetcode-cn.com/problems/longest-palindromic-substring/

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

=============================================================
题解：

有两种情况：
1. 最大回文长度为奇数
2. 最大回文长度为偶数

注意两个边界：

1. 以i为中心向两边扩散。注意边界ExpandPalindrome()的返回值需要把i和j本身剔除掉。
返回值应该为：j - i + 1 - 2
2. start和end的值。特别是start值的确定。这个表达式是综合了偶数和奇数两种情况计算出来的结果。
    
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;

        int maxLen = 1;
        int start = 0, end = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            int odd = ExpandPalindrome(s, i, i);
            int even = ExpandPalindrome(s, i, i + 1);
            int maxLen = max(odd, even);
            if (maxLen > end - start) {
                start = i - (maxLen - 1) / 2; // start值的确定
                end = i + maxLen / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int ExpandPalindrome(string s, int left, int right) {
        int len = s.size();
        int i = left, j = right;
        while (i >= 0 && j < len) {
            if (s[i] == s[j]){
                i--;
                j++;
            } else {
                break;
            }
        }
        return j - i - 1;
    }

};
