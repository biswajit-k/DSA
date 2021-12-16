/*

submitted solution - O(n), space- O(n)
idea - we need to find max value of 2 difference in array i.e max (a[c] - a[b]) + (a[e] - a[d])

so i created 2 array left and right, left store max difference possible from 0 to i
right store max dirrerence possible from i to n-1

finally i find max value of left[i] + right[i + 1]

BETTER SOLUTION - O(n) , O(1) space
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution

another solution by simplifying above dp - 

idea - we can either (buy 1 and sell 1) or (buy 2 and sell 2)

now buy1 and sell1 is simple i.e for a day - if it is cheaper than previous buy price
buy it . and if price is high than previous sell, sell it - store profit in sell1 

buy2 is combined price of previous buy-sell and today price i.e buy2 is price today - profit of sell1
sell2 is simply max profit on selling today with buy2

code - 

var maxProfit = function(prices) {
  let oneBuyOneSell = 0;
  let twoBuyTwoSell = 0;
  let oneBuy = Number.POSITIVE_INFINITY;
  let twoBuy = Number.POSITIVE_INFINITY;
  
  for(let i = 0; i < prices.length; i++) {
    const p = prices[i];
    oneBuy = Math.min(oneBuy, p);
    oneBuyOneSell = Math.max(oneBuyOneSell, p - oneBuy);
    twoBuy = Math.min(twoBuy, p - oneBuyOneSell);// buy asif price is reduce by prev. profit
    twoBuyTwoSell = Math.max(twoBuyTwoSell, p - twoBuy);
  }
  
  return twoBuyTwoSell;
};

*/

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