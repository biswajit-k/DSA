class Solution {
public:
    int numDistinct(string s, string t) {
        
        unsigned long long int ss = s.length(), st = t.length(), dp[1004];
        memset(dp, 0, sizeof(dp));
        
        for(auto c: s)
        {
            for(int i = st; i >= 1; i--)
            {
                if(t[i - 1] == c)
                {
                    dp[i] += (i - 1 == 0 ? 1: dp[i - 1]);
                    
                }
                // if(i == st - 2)
                //     cout << dp[i] << ' ' << c << '\n';
                    
                
            }
        }
        
        return dp[st];
        
        
    }
};