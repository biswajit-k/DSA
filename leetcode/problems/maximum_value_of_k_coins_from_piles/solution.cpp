class Solution {
public:

    const int inf = 1e9;

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n = piles.size();

        vector<int> dp1(k + 1, -inf), dp2(k + 1, -inf);

        // dp[x][idx] : max value we can get from picking x coins from idx(th) till end pile
        // dp[x][idx] = max { sum(piles[idx][0...i-1]) + dp[x - i][idx + 1] } for i = 1 till min(x, size of idx(th) pile)

        dp1[0] = dp2[0] = 0;
        
        for(int idx = n - 1; idx > -1; idx--)
        {
            int m = piles[idx].size();
            for(int i = 1; i <= k; i++)
            {
                dp2[i] = dp1[i];
                int collected = 0;
                for(int j = 1; j <= min(i, m); j++)
                {
                    collected += piles[idx][j - 1];
                    dp2[i] = max(dp2[i], collected + dp1[i - j]);
                }
            }
            swap(dp1, dp2);
        }

        return dp1[k];
    }
};