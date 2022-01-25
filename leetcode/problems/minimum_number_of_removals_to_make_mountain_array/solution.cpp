class Solution {
    
    // const int nax = 1005;
    
    void doit(vector<int>& a, vector<int>& dp)
    {
        dp[0] = 1;
        for(int i = 1; i < (int)a.size(); i++)
        {
            dp[i] = 1;
            for(int j = 0; j < i; j++)
                if(a[j] < a[i])
                    dp[i] = max(dp[i], dp[j] + 1);
        }   
    }
    
    
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(2000), right(2000);
        doit(nums, left);
        reverse(nums.begin(), nums.end());
        doit(nums, right);
        reverse(right.begin(), right.begin() + n);
        
        int ans = 0;
        for(int i = 1; i < n - 1; i++)
        {
            if(left[i] > 1 && right[i] > 1)
            ans = max(ans, left[i] + right[i] - 1);
            
        }
        
        return n - ans;
        
    }
};