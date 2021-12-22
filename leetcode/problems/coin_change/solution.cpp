class Solution {
public:
    int mincoin[100008];
    
    int minCoins(vector<int>& coins, int amount){
        if(amount == 0)
                return 0;
        if(mincoin[amount] < 100005)
            return mincoin[amount];
        
        for(auto coin: coins)
        {
            if(amount - coin >= 0)
            {
                int amt = minCoins(coins, amount - coin);
                if(amt == -1)
                    continue;
                mincoin[amount] = min(mincoin[amount], 1 + amt);   
            }
            else 
                break;
            
        }
        if(mincoin[amount] < 100005)
            return mincoin[amount];
        return mincoin[amount] = -1;
    
    }
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        for(int i = 0; i < 100006; i++)
                mincoin[i] = 100008;
        int amt = minCoins(coins, amount);
        if(amt > 100005)
            return -1;
        return amt;
    }
};