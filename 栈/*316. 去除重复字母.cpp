316. 去除重复字母

给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters 相同

示例 1：

输入：s = "bcabc"
输出："abc"
示例 2：

输入：s = "cbacdcbc"
输出："acdb"

题解：

1. we save the occurance of each char in s by using vector<int> dict(256,0)
2. we make a result string
3. traverse the string again, each time we see a char, we decrease the occurance in the dict, 
and check if this char has been in the result or not, 
if so, skip the char while the result.back() is larger than current char, 
we check if we can still see this result.back() in the latter substring. 
if we can still find it later, we can pop it from the back and add it back later
4. add current char to the back of the result string
5. set visited[current char]=true
    
如果当前char比栈顶char小，并且从dict得知后面的string里面这个char还存在，那么把栈顶出栈，并且unset它的visit值，然后把当前char入栈。

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> dict(256, 0); // freq
        vector<bool> visited(256, false); // visited
        string ans = "";
        for (char c : s) ++dict[c];
        for (int i = 0; i < s.size(); ++i) {
            --dict[s[i]];
            if (visited[s[i]]) continue;
            while (!ans.empty() && s[i] < ans.back() && dict[ans.back()] > 0) {
                visited[ans.back()] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            visited[s[i]] = true;
        }
        return ans;
    }
};

