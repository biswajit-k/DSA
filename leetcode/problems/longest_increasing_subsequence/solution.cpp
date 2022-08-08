class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> lis;
        
        for(auto& x: nums)
        {
            auto it = lower_bound(begin(lis), end(lis), x);
            if(it == lis.end())
                lis.push_back(x);
            else 
                *it = x;
        }
        
        return int(lis.size());
        
    }
};