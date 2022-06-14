class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length(), m = word2.length();
        vector<int> dp(m + 1, 0);
        
        for(int i = 0; i < n; i++)
        {
            int taken = 0;
            for(int j = 0; j < m; j++)
            {
                int tp = dp[j];
                if(word1[i] == word2[j])
                    dp[j] = max(dp[j], taken + 1);
                taken = max(taken, tp);
            }
                
        }
        
        return (m + n - 2 * *max_element(begin(dp), end(dp)));
    }
};