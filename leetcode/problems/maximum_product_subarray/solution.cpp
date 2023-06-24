class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size(), pos = 0, neg = 0;
        int mx = *max_element(begin(nums), end(nums));

        for(int i = n - 1; i > -1; i--)
        {
            if(nums[i] > 0)
            {
                pos = max(nums[i] * pos, nums[i]);
                neg = nums[i] * neg;
            }
            else if(nums[i] < 0) 
            {
                int temp = neg;
                neg = min(nums[i] * pos, nums[i]);
                pos = nums[i] * temp;
            }
            else 
                pos = neg = 0;
            
            if(pos)
                mx = max(mx, pos);
        }

        return mx;
    }
};