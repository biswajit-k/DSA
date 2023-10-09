class Solution {
public:
    int burst(int l, int r, int a[], int dp[][300]) {

        if(l > r)
            return 0;

        if(dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;
        for(int i = l; i <= r; i++)
        {
            int curr = (a[l - 1] * a[i] * a[r + 1]) + burst(l, i - 1, a, dp) + burst(i + 1, r, a, dp);
            ans = max(ans, curr);
        }

        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums){

        int n = nums.size();

        int a[n + 2], len = 1;
        for(int i = 0; i < n; i++)
            if(nums[i] > 0)
            {
                a[len] = nums[i];
                len++;
            }

        a[0] = a[len++] = 1;

        int dp[len][300];
        memset(dp, -1, sizeof(dp));

        int ans = burst(1, len - 2, a, dp);

        // cout << dp[1][2] << ' ' << dp[2][3] << ' ' << dp[3][3];

        return ans;
    }
};