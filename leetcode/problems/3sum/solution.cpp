class Solution {
public:
    
       vector<vector<int>> twoSum(vector<int>& nums, int l, int r, int x)
    {
        vector<vector<int>> res;
        while(l < r)
        {
            if(nums[l] + nums[r] == x)
                res.push_back(vector<int>({nums[l], nums[r]}));
            
            
            if(nums[l] + nums[r] < x)
            {
                while(l < r && nums[l] == nums[l + 1])
                    l++;
                l++;
            }
                
            else 
            {
                while(l < r && nums[r] == nums[r - 1])
                    r--;
                r--;
            }
                
        }
        
        return res;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(begin(nums), end(nums));
        int l = 0, r = nums.size() - 1, x = 0;
        vector<vector<int>> res;
        
        for(int i = l; i < r - 1; i++)
        {
            vector<vector<int>> temp = twoSum(nums, i + 1, r, x - nums[i]);
            
            for(auto& v: temp)
            {
                v.push_back(nums[i]);
                res.push_back(move(v));
            }               
            
            while(i + 1 < r && nums[i] == nums[i + 1])  i++;
        }
        
        return res;
    }
    
    
};