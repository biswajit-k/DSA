class Solution {
public:
    
    typedef long long llint;
    
    long long maximumSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<llint> base;
        for(int i = 1; i * i <= n; i++)
            base.push_back(i * i);
        
        llint ans = 0;
        for(int i = 1; i <= n; i++)
        {
            llint sum = 0;
            for(auto& idx: base)
            {
                if(idx * i > n)
                    break;
                sum += nums[idx * i - 1];
            }
            ans = max(ans, sum);
        }
        
        return ans;
    }
};