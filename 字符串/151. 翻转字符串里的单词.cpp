151. 翻转字符串里的单词

示例 4：
输入：s = "  Bob    Loves  Alice   "
输出："Alice Loves Bob"
    
示例 5：
输入：s = "Alice does not even like bob"
输出："bob like even not does Alice"

解题分析：

1. 这里的设计引入一个storeIndex来记录当前处理到的字符串下标，包含空格和字母。

2. 引入j用来记录处理的某一个单词时候字母的下标。

3. i永远是某一个单词的词首字母，还有遇到空格就跳过。如果遇到不是空格就开始新一轮单词的处理。
每轮处理都会走完一个单词。如果storeIndex不为0，说明不是第一个单词，这时候就要加一个空格。

"the sky is blue" 第一次反转以后为
"eulb si yks eht"

在处理循环处理第一个单词时
while (j < n && s[j] != ' ') s[storeIndex++] = s[j++];
上面循环结束后 i=0, j=4, storeIndex=4
计算单词长度为4。
注意：reverse(first, last)函数只反转[first, last)区间，所以s[4]=' '不参与反转。

完全翻转以后结果为：
"blue is sky the"
    
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

class Solution {
public:
    string reverseWords(string s) {
        int storeIndex = 0, n = s.size();
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (storeIndex != 0) s[storeIndex++] = ' ';
                int j = i;
                while (j < s.size() && s[j] != ' ') {
                    s[storeIndex++] = s[j++];
                }
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
            }
        }
        s.resize(storeIndex);
        return s;
    }
};
                             
