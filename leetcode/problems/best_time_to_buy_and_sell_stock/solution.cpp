class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0, buy = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < prices[buy])
                buy = i;
            else
                profit = max(profit, prices[i] - prices[buy]);
        }
        
        return profit;
        
    }
};