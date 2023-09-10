class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        
        int n = nums.size(), pts = 0;
        
        sort(begin(nums), end(nums));
        
        int least_start = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i][0] >= least_start)
            {
                pts += nums[i][1] - nums[i][0] + 1;
                least_start = nums[i][1] + 1;
            }
            else
            {
                pts += max(0, nums[i][1] - least_start + 1);
                least_start = max(least_start, nums[i][1] + 1);
            }
        }
        
        return pts;
    }
};