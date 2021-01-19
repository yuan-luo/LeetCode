651. 4键键盘

假设你有一个特殊的键盘包含下面的按键：

Key 1: (A)：在屏幕上打印一个 'A'。
Key 2: (Ctrl-A)：选中整个屏幕。
Key 3: (Ctrl-C)：复制选中区域到缓冲区。
Key 4: (Ctrl-V)：将缓冲区内容输出到上次输入的结束位置，并显示在屏幕上。

现在，你只可以按键 N 次（使用上述四种按键），请问屏幕上最多可以显示几个 'A'呢？

class Solution {
public:
    int maxA(int N) {
        // dp[i]表示步骤总数为i时，能打印出的最多A的个数
        vector<int> dp(N + 1, 0);
        for (int i = 0; i <= N; ++i) {
            dp[i] = i;
            for (int j = 1; j < i - 2; ++j) {
                dp[i] = max(dp[i], dp[j] * dp[i - j - 1]);
            }
        }
        return dp[N];
    }
};
