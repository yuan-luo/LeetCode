738. 单调递增的数字

给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string n_str = to_string(N);
        int marker= n_str.size();
        for (int i = n_str.size() - 1; i > 0; --i) {
            if (n_str[i] < n_str[i - 1]) {
                marker = i;
                n_str[i - 1] = n_str[i - 1] - 1;
            }
        }
        for (int i = marker; i < n_str.size(); ++i) n_str[i] = '9';
        return stoi(n_str);
    }
};
