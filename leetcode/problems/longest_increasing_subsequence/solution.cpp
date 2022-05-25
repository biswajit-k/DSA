class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        
        for(int i = 0; i < n; i++)
        {
            auto it = lower_bound(begin(ans), end(ans), nums[i]);
            if(it == end(ans))
                ans.push_back(nums[i]);
            else 
                *it = nums[i];
        }
        
        return int(size(ans));
        
    }
};