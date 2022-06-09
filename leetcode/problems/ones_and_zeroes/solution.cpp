class Solution {
public:
    
    int dp[101][101];
    
    int findMaxForm(vector<string>& strs, int m, int n) {
      
        for(int i = 0; i < 101; i++)
            for(int j = 0; j < 101; j++)
                dp[i][j] = 0;
        
        for(int i = 0; i < strs.size(); i++)
        {
            int zero = count(begin(strs[i]), end(strs[i]), '0');
            int one = strs[i].length() - zero;
            
            for(int j = m; j >= zero; j--)
                for(int k = n; k >= one; k--)
                    dp[j][k] = max(dp[j][k], 1 + dp[j - zero][k - one]);
            
        }
        
        return dp[m][n];
    }
};