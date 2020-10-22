309. 最佳买卖股票时机含冷冻期

https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        vector<int> hold(prices.size(), 0);
        vector<int> unhold(prices.size(), 0);
        hold[0] = - prices[0];
        hold[1] = max( -prices[0], -prices[1]);
        unhold[0] = 0;
        
        for (int i = 1; i < prices.size(); ++i) {
            unhold[i] = max(hold[i - 1] + prices[i], unhold[i - 1]);                        
            if (i == 1) continue;
            hold[i] = max(unhold[i - 2] - prices[i], hold[i - 1]);            
        }
        return unhold.back();
    }
};
