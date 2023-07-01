class Solution {
public:

    const int inf = 1e8;

    void get_set_bits(int mask, vector<int>& set_bits) {

        for(int i = 0; mask; i++, mask >>= 1)
            if(mask & 1)
                set_bits.push_back(i);
    }

    int minimum_unfairness(int mask, int k, vector<int>& cookies, vector<vector<int>>& dp) {

        if(mask == 0)   return 0;
        if(k == 0)  return inf;

        if(dp[k][mask] != -1)   return dp[k][mask];

        vector<int> set_bits;
        get_set_bits(mask, set_bits);
        int sz = set_bits.size(), ans = inf;
        
        for(int i = 0; i < (1 << sz); i++)
        {
            int taken = 0, taken_mask = 0;
            for(int j = 0; j < sz; j++)
                if(i & (1 << j))
                {
                    taken += cookies[set_bits[j]];
                    taken_mask |= (1 << set_bits[j]);
                }
            
            ans = min(ans, max(taken, minimum_unfairness(mask ^ taken_mask, k - 1, cookies, dp)));
        }

        return dp[k][mask] = ans;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        
        int n = cookies.size();

        vector<vector<int>> dp(k + 1, vector<int>(1 << n, -1));

        return minimum_unfairness((1 << n) - 1, k, cookies, dp);
    }
};