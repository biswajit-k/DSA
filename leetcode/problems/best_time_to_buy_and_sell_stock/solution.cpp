class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int bp = prices[0], pr = 0;
        for(auto price: prices)
        {
            if(price < bp)
            {
                bp = price;
            }
            pr = max(pr, price - bp);
            
        }
        
        return pr;
    }
};