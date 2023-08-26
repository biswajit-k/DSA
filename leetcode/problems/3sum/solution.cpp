class Solution {
public:

    void next(int& i, vector<int>& nums, int step = 1) {
        i += step;  
        while(i > 0 && i < nums.size() && nums[i] == nums[i - step])
            i += step;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;

        sort(begin(nums), end(nums));

        for(int i = 0; i < n; next(i, nums))
        {
            for(int j = i + 1, k = n - 1; j < k; next(j, nums))
            {
                int required = -(nums[i] + nums[j]);
                while(j < k && nums[k] > required)
                    k--;
                
                if(j < k && nums[k] == required)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    next(k, nums, -1);
                }
            }
        }

        return ans;
    }
};