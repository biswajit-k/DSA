class Solution {
    
    
public:
    typedef long long llint;
    
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
     
        llint ans = 0;
        
        for(int i = 0; i < k; i++)
        {
            auto& mixture = composition[i];
            
            llint l = 0, r = 1e9, mixture_ans = 0;
            
            while(l <= r)
            {
                llint alloys = (l + r) / 2;
                
                llint money_remain = budget;
                bool possible = true;
                
                // check overflows
                for(int j = 0; j < n; j++)
                {
                    llint metal = mixture[j] * 1LL * alloys;
                    llint needed = metal - stock[j];
                    if(needed > 0)
                    {
                        money_remain -= cost[j] * 1LL * needed;
                        if(money_remain < 0)
                        {
                            possible = false;
                            break;
                        }
                    }
                }
                
                if(possible)
                {
                    ans = max(ans, alloys);
                    l = alloys + 1;
                }
                else 
                    r = alloys - 1; 
            }
        }
        
        return ans;
    }
};