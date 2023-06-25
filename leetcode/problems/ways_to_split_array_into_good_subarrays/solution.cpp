class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        
        if(count(begin(nums), end(nums), 1) == 0)
            return 0;
        
        long long n = nums.size(), ans = 1;
        
        int z = 0;
        int i = 0;
        while(i < n && nums[i] == 0)    i++;
        
        for(i = i + 1; i < n; i++)
        {
            if(nums[i])
            {
                ans = (ans * (z + 1)) % mod;
                z = 0;
            }
            else 
                z++;
        }
        
        return ans;
    }
};