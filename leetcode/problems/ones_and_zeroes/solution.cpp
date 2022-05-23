class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<int>> dp1(m + 1, vector<int>(n + 1, 0));
        
        vector<pair<int, int>> a(strs.size());
        
        for(int i = 0; i < strs.size(); i++)
        {
            a[i].first = count(strs[i].begin(), strs[i].end(), '0');
            a[i].second = int(strs[i].size()) - a[i].first;
        }
        
        
        for(auto [p, q]: a)
        {
        
            for(int i = m; i > -1; i--)
            {
                if(i - p < 0)   break;
                for(int j = n; j > -1; j--)
                {
                    if(j - q < 0)   break;
                    dp1[i][j] = max(dp1[i][j], 1 + dp1[i - p][j - q]);
                }
            }
        }
        
        return dp1[m][n];
            
        
    }
};