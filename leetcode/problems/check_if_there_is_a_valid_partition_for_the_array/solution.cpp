class Solution {
public:
    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        vector<bool> valid(n + 1, 0);
        
        valid[0] = 1;
        valid[1] = 0;
        valid[2] = (nums[0] == nums[1]);
        
        
        auto is_valid = [&](int i) {
            if(nums[i] == nums[i - 1] && valid[i - 1])  return 1;
            if(valid[i - 2])
            {
                if(nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2])
                    return 1;
                if(nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1)
                    return 1;
            }
            return 0;
        };
        
        for(int i = 2; i < n; i++)
            if(is_valid(i))
                valid[i + 1] = 1;
        
        return valid[n];
    }
};