class Solution {
public:
    
    int freq[21], n;
    vector<vector<int>> ans;
    
    void helper(vector<int> sol)
    {
        if(sol.size() == n)
        {
            ans.push_back(sol);
            return;
        }
        for(int i = 0; i < 21; i++)
            if(freq[i])
            {
                sol.push_back(i - 10);
                freq[i]--;
                helper(sol);
                sol.pop_back();
                freq[i]++;
            }
        
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> sol;
        memset(freq, 0, sizeof(freq));
        
        for(auto x: nums)
            freq[x + 10]++;
        
        n = nums.size();
        helper(sol);
        
        return ans;
    }
};