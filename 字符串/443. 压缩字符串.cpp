443. 压缩字符串

输入：
["a","a","b","b","c","c","c"]

输出：
返回 6 ，输入数组的前 6 个字符应该是：["a","2","b","2","c","3"]

说明：
"aa" 被 "a2" 替代。"bb" 被 "b2" 替代。"ccc" 被 "c3" 替代。

class Solution {
public:
    int compress(vector<char>& chars) {
        int curr = 0, res = 0;
        for (int start = 0, end = 0; start < chars.size(); start = end) {
            while (end < chars.size() && chars[start] == chars[end]) end++;
            chars[curr++] = chars[start];

            if (end - start == 1) continue;

            for (auto c : to_string(end - start)) { 
                chars[curr++] = c;
            }
        }
        return curr;
    }
};
