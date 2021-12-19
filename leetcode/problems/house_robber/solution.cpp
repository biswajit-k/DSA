class Solution {
public:
    int rob(vector<int>& nums) {
        int wo = 0, wi = nums[0];
        
        for(int i = 1; i < (int)nums.size(); i++)
        {
            int tp = wo;
            wo = max(wo, wi);
            wi = tp + nums[i];
        }
        return max(wo, wi);
    }   
};