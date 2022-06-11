class Solution {
public:
    
    vector<vector<int>> ans;
    
    vector<vector<int>> threeSum(vector<int>& nums) {
    
        if(nums.size() < 3)
            return ans;
        
        int n = nums.size();
        sort(begin(nums), end(nums));
        
        set<multiset<int>> res;
        
        for(int i = 2; i < n; i++)
            if(i < 5 || nums[i] != nums[i - 3])
            for(int j = i - 1; j > 0; j--)
            {
                auto it = lower_bound(begin(nums), begin(nums) + j, -(nums[i] + nums[j]));
                if(it - nums.begin() < j && *it == -(nums[i] + nums[j]))
                    res.insert(multiset<int>({nums[i], nums[j], *it}));
            }
        
        ans.reserve(res.size());
        for(auto& s: res)
            ans.push_back(vector<int>(s.begin(), s.end()));
        
        return ans;
             
    }
    
    
};