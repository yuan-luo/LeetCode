443. 压缩字符串

给定一组字符，使用原地算法将其压缩。

压缩后的长度必须始终小于或等于原数组长度。

数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。

在完成原地修改输入数组后，返回数组的新长度。


输入：
["a","a","b","b","c","c","c"]

输出：
返回 6 ，输入数组的前 6 个字符应该是：["a","2","b","2","c","3"]

说明：
"aa" 被 "a2" 替代。"bb" 被 "b2" 替代。"ccc" 被 "c3" 替代。

=======================================================


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
