class Solution {
public:

    int helper(int pos, int mask, vector<int>& dp) {

        if(mask == 0)   return 1;

        if(dp[mask] != -1)  return dp[mask];

        int res = 0;
        for(int i = 0; i < 15; i++)
            if((mask & (1 << i)) && (pos % (i + 1) == 0 || (i + 1) % pos == 0))
                res += helper(pos - 1, mask & ~(1 << i), dp);

        return dp[mask] = res;
    }


    int countArrangement(int n) {
        
        vector<int> dp(1 << n, -1);

        int ans = helper(n, (1 << n) - 1, dp);
        return ans;
    }
};