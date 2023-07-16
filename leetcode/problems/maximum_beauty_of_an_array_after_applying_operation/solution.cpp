class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        
        int n = nums.size(), len = 0;
        
        sort(begin(nums), end(nums));
        
        for(int i = 0; i <= nums[n - 1]; i++)
        {
            auto l_idx = lower_bound(begin(nums), end(nums), i - k);
            auto r_idx = upper_bound(begin(nums), end(nums), i + k);
            
            len = max(len, int(r_idx - l_idx));
        }
        
        return len;
    }
};