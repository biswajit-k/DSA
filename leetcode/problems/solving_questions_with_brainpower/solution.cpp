class Solution {
public:
    long long mostPoints(vector<vector<int>>& Q) {
        
        int n = Q.size();
        vector<long long> dp(n, 0);

        dp[n - 1] = Q[n -1][0];

        for(int i = n - 2; i > -1; i--)
        {
            dp[i] = Q[i][0] + (i + Q[i][1] + 1 < n ? dp[i + Q[i][1] + 1] : 0);
            dp[i] = max(dp[i], dp[i + 1]);
        }

        return dp[0];
    }
};