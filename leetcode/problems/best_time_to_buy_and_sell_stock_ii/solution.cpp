class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        int profit = 0, buy = prices[0];

        for(auto& price: prices)
        {
            if(price > buy)
                profit += price - buy;

            buy = price;
        }

        return profit;
    }
};