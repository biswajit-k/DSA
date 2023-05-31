class Solution {
public:

    const int inf = 1e9;
    int dp[31][31][31];

    int mergeStones(vector<int>& S, int k) {
        
        int n = S.size();
        vector<int> prefix(n + 1, 0);
        partial_sum(begin(S), end(S), begin(prefix) + 1);

        for(int i = 0; i < 31; i++)
            for(int j = 0; j < 31; j++)
                for(int k = 0; k < 31; k++)
                    dp[i][j][k] = inf;

        for(int i = 0; i < 31; i++)
            dp[i][i][1] = 0;

        for(int len = 1; len < n; len++)
        {
            for(int i = 0; i + len < n; i++)
            {
                for(int j = 2; j <= k; j++)
                {
                    for(int m = i; m < i + len; m++)
                    {
                        int v1 = dp[i][m][1];
                        int v2 = dp[m + 1][i + len][j - 1];
                        dp[i][i + len][j] = min(dp[i][i + len][j], v1 + v2);
                    }
                }
                int v = dp[i][i + len][k];
                dp[i][i + len][1] = v == inf ? inf : v + prefix[i + len + 1] - prefix[i];
            }
        }

        return dp[0][n - 1][1] == inf ? -1 : dp[0][n -1][1];
    }
};