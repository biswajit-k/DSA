class Solution {
public:

    const int inf = 98878778;
    
    int helper(vector<int>& cookies, vector<int>& dp, int k, int pos)
    {
        if(pos == cookies.size())
        {
            return *max_element(begin(dp), end(dp));
        }
        int mi = inf;
        for(int i = 0; i < k; i++)
        {
            dp[i] += cookies[pos];
            mi = min(mi, helper(cookies, dp, k, pos + 1));
            dp[i] -= cookies[pos];
        }
        
        return mi;
    }

    int distributeCookies(vector<int>& cookies, int k) {
       
        int n = cookies.size();
        vector<int> dp(k, 0);
        
        return helper(cookies, dp, k, 0);

    }
};