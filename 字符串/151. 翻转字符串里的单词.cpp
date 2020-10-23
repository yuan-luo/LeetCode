151. 翻转字符串里的单词

https://leetcode-cn.com/problems/reverse-words-in-a-string/

给定一个字符串，逐个翻转字符串中的每个单词。

说明：

无空格字符构成一个 单词 。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

示例 1：

输入："the sky is blue"
输出："blue is sky the"
示例 2：

输入："  hello world!  "
输出："world! hello"
解释：输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入："a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
示例 4：

输入：s = "  Bob    Loves  Alice   "
输出："Alice Loves Bob"
示例 5：

输入：s = "Alice does not even like bob"
输出："bob like even not does Alice"


class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int storeIndex = 0; // storeIndex为该单词真正处理到的字符的右界下标
        int n = s.size();
        for (int i = 0; i < n; ++i) {
        
            // 当s[i]不为空格的时候，如果不是第一个字符，那么加一个空格。
            if (s[i] != ' ') {
                if (storeIndex != 0) s[storeIndex++] = ' ';
                int j = i;
                
                // 循环处理一个单词
                while (j < n && s[j] != ' ') s[storeIndex++] = s[j++];
                
                // 反转这个单词，j - i为单词长度
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                
                // 下标指向单词尾部的下一个位置
                i = j;
            }
        }
        s.resize(storeIndex);
        return s;
    }
};

分析：

"the sky is blue" 第一次反转以后为
"eulb si yks eht"

在处理循环处理第一个单词时
while (j < n && s[j] != ' ') s[storeIndex++] = s[j++];
上面循环结束后 i=0, j=4, storeIndex=4
计算单词长度为4。
注意：reverse(first, last)函数只反转[first, last)区间，所以s[4]=' '不参与反转。

"blue is sky the"

