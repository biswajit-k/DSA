class Solution {
public:
    int left[int(1e5) + 5] = {}, right[int(1e5) + 5] = {};
    
    int maxProfit(vector<int>& prices) {
        
        int b = prices[0], p = 0, i = 0;
        for(auto price: prices)
        {
            if(price <= b)
                b = price;
            else
                p = max(p, price - b);
            
            left[i] = p;
            i++;
        }
        i--;
        int s = prices[i];
        p = 0;
        while(i > -1)
        {
            if(prices[i] > s)
                s = prices[i];
            else 
                p = max(p, s - prices[i]);
            right[i] = p;
            i--;
        }
        int ans = 0;
        for(int j = 0; j < int(prices.size()); j++)
            ans = max(ans, left[j] + right[j + 1]);
        
        return ans;
        
        
        
    }
};