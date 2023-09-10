class Solution {
public:
    
    typedef pair<int, int> pii;
    
    int get_count(int x) {
        int c = 0;
        while(x)
        {
            c += x % 2;
            x /= 2;
        }
        return c;
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        
        int n = 3;
        
        vector<pii> extra, nil;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < grid[i][j] - 1; k++)
                    extra.push_back({i, j});
                if(grid[i][j] == 0)
                    nil.push_back({i, j});
            }
        
        int sz = extra.size();
        
        const int inf = 1e8;
        vector<vector<int>> dp(sz, vector<int>(1 << sz, inf));
        
        for(int i = 0; i < sz; i++)
        {
            for(int j = 0; j < (1 << sz); j++)
            {
                
                if(get_count(j) != i + 1)
                    continue;
                // if(i == 0)
                //     cout << j << ' ';
                for(int k = 0; k < sz; k++)
                {
                    if((j & (1 << k)) == 0)
                        continue;
                    if(i == 0 && j == 2)
                        cout << k << '\n';
                    int mask = j & ~(1 << k);
                    dp[i][j] = min(dp[i][j], abs(extra[i].first - nil[k].first) + abs(extra[i].second - nil[k].second) + (i == 0 ? 0 : dp[i - 1][mask]));
                }
                
            }
        }
        // cout << dp[0][1] << ' ' << dp[0][2] << ' ' << dp[1][3];
        return dp[sz - 1][(1 << sz) - 1];
    }
};