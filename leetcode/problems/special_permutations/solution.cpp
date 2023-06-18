class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    
    int helper(int last, int my_mask, vector<int>& nums, unordered_map<int, unordered_map<int, int>>& dp) {
        
        if(my_mask == 0)   return 1;
        
        if(dp.count(last) && dp[last].count(my_mask))  return dp[last][my_mask];
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if((my_mask & (1 << i)) && (nums[i] % last == 0 || last % nums[i] == 0))
            {
                ans = (ans + helper(nums[i], my_mask & ~(1 << i), nums, dp)) % mod;
            }
        }
        return dp[last][my_mask] = ans;
    }
    
    
    int specialPerm(vector<int>& nums) {
     
        int n = nums.size();
        unordered_map<int, unordered_map<int, int>> dp;
        
        return helper(1, (1 << n) - 1, nums, dp);
    }
};