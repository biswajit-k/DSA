class Solution {
public:
    
    vector<vector<int>> twoSum(vector<int>& nums, int l, int r, int x)
    {
        vector<vector<int>> res;
        if(abs(x) > 1e9)    return res;
        
        while(l < r)
        {
            int sum = nums[l] + nums[r];
            
            if(sum < x)
                l++;
            else if(sum > x)
                r--;
            else 
            {
                vector<int> ans = {nums[l], nums[r]};
                while(l < r && nums[l] == ans[0])   l++;
                while(l < r && nums[r] == ans[1])   r--;
                res.push_back(move(ans));
            }
        }
        
        return res;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums, int l, int r, int x)
    {
        vector<vector<int>> res;
        if(abs(x) > 1e9)    return res;
        
        for(int i = l; i < r; i++)
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
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        
        for(int i = 0; i < nums.size() - 1; i++)
        {
            vector<vector<int>> temp = threeSum(nums, i + 1, nums.size() - 1, target - nums[i]);
            
            for(auto& v: temp)
            {
                v.push_back(nums[i]);
                res.push_back(move(v));
            }               
            
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])  i++;
        }
        
        return res;
    }
};