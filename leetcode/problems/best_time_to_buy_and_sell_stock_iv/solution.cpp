class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();

        vector<int> profit(k + 1, 0), prev_profit_with_buy(k, -prices[0]);

        for(int i = 1; i < n; i++)
        {
            for(int j = k; j >= 1; j--)
            {
                profit[j] = max(profit[j], prices[i] + prev_profit_with_buy[j - 1]);
                prev_profit_with_buy[j - 1] = max(prev_profit_with_buy[j - 1], -prices[i] + profit[j - 1]);
            }

        }

        return profit[k];
    }
};