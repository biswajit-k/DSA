class Solution {
public:
   
    
    int coinChange(vector<int>& coins, int amount) {
        
        const int inf = 1000000;
        
        vector<int> dp(amount + 1, 0);
        for(auto x: coins)
            if(x <= amount) dp[x] = 1;
        
        for(int i = 1; i <= amount; i++)
        {
            int mi = inf;
            for(auto x: coins)
                if(i - x >= 0)
                    mi = min(mi, 1 + dp[i - x]);
            dp[i] = mi;
        }
        return (dp[amount] >= inf ? -1 : dp[amount]);
        
    }
};