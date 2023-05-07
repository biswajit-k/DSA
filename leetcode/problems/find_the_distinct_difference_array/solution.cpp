class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> l, r;
        for(int i = 0; i < n; i++)  r[nums[i]]++;
        
        vector<int> ans(n);
        int ld = 0, rd = r.size();
        for(int i = 0; i < n; i++)
        {
            r[nums[i]]--;
            if(r[nums[i]] == 0) r.erase(nums[i]), rd--;
            l[nums[i]]++;
            if(l[nums[i]] == 1) ld++;
            
            ans[i] = ld - rd;
        }
        
        return ans;
    }
};