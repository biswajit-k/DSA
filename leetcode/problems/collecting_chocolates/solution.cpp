class Solution {
public:
    typedef long long llint;
    
    long long minCost(vector<int>& nums, int x) {
        
        llint n = nums.size(), total = accumulate(begin(nums), end(nums), 0LL), ans = total;
        
        vector<llint> min_cost(begin(nums), end(nums));
        
        for(int k = 1; k < n; k++)
        {
            llint rot_cost = x * 1LL * k;
            
            for(int i = 0; i < n ;i++)
                if(nums[(i + k) % n] < min_cost[i])
                {
                    total += nums[(i + k) % n] - min_cost[i];
                    min_cost[i] = nums[(i + k) % n];
                }
                
            ans = min(ans, total + rot_cost);
        }
        
        return ans;
    }
};