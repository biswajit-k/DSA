class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idx, int val) {
        
        int n = nums.size();
        unordered_map<int, int> val_to_idx;
        
        set<int> collection;
        
        vector<int> ans = {-1, -1};
        
        for(int i = n - 1 - idx; i > -1; i--)
        {
            collection.insert(nums[i + idx]);
            val_to_idx[nums[i + idx]] = i + idx;
            
            if(abs(*collection.begin() - nums[i]) >= val)
            {
                ans = {i, val_to_idx[*collection.begin()]};
                break;
            }
            if(abs(*collection.rbegin() - nums[i]) >= val)
            {
                ans = {i, val_to_idx[*collection.rbegin()]};
                break;
            }    
            
        }
        
        return ans;
    }
};