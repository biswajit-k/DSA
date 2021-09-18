class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bp = prices[0], pr = 0;
        for(auto price: prices){
            if(price < bp){
                bp = price;
            }
            else{
                pr += price - bp;
                bp = price;
            }
        }
        
        return pr;
    }
};