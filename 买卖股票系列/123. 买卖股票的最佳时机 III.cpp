123. 买卖股票的最佳时机 III

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

思路：

forward是指左边的最大利润，就是以前买入最晚到今天卖出一次的最大利润。
backward是指右边的最大利润，就是最早今天买入一次到以后卖出的最大利润。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res;
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> forward(prices.size(), 0);
        vector<int> backward(prices.size(), 0);

        int minValue = prices[0];
        for (int i = 1; i < prices.size() - 1; ++i) {
            minValue = min(minValue, prices[i]);
            forward[i] = max(forward[i - 1], prices[i] - minValue);
        }

        int maxValue = prices[n - 1];
        for (int i = prices.size() - 2; i >= 0; --i) {
            maxValue = max(maxValue, prices[i]);
            backward[i] = max(backward[i + 1], maxValue - prices[i]);
        }

        for (int i = 0; i < prices.size(); ++i) {
            res = max(res, forward[i] + backward[i]);
        }

        return res;
    }
};
