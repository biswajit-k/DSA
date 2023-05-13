class Solution {
public:

    const int mod = 1e9 + 7;

    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int> dp(high + 1, 0);
        dp[0] = 1;

        for(int i = 0; i + min(zero, one) <= high; i++)
        {
            if(i + zero <= high)
                dp[i + zero] = (dp[i + zero] + dp[i]) % mod;
            if(i + one <= high)
                dp[i + one] = (dp[i + one] + dp[i]) % mod;
        }

        auto with_mod = [&](int sum, int x) {
            return (sum + x) % mod;
        };

        int ans = accumulate(dp.begin() + low, dp.end(), 0, with_mod);

        return ans;
    }
};