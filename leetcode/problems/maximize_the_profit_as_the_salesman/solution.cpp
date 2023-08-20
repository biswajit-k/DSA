class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        
        int m = offers.size();
        vector<int> dp(n, 0);
        
        sort(begin(offers), end(offers), [&](vector<int>& a, vector<int>& b) {
            return a[1] < b[1]; 
        });
        
        int ans = 0;
        for(int i = 0, j = 0; i < n; i++)
        {
            dp[i] = i > 0 ? dp[i - 1] : 0;
            while(j < m && offers[j][1] == i)
            {
                dp[i] = max(dp[i], offers[j][2] + (offers[j][0] > 0 ? dp[offers[j][0] - 1] : 0));
                j++;
            }
        }
        
        return dp[n - 1];
    }
};