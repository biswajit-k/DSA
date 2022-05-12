class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        int cnt = 1;
        for(int i = 2; i <= nums.size(); i++)
            cnt *= i;
        
        for(int i = 0; i < cnt; i++)
        {
            next(nums);
            ans.push_back(nums);
        }
        return ans;
    }
    
    void next(vector<int>& nums){
        int n = nums.size();
        if(n <= 1)
            return;
        
        int pos = n - 2;
        for(; pos > -1; pos--)
        {
            if(nums[pos] < nums[pos + 1])
                break;
        }
        if(pos == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        reverse(nums.begin() + pos + 1, nums.end());
        for(int i = pos + 1; i < n; i++)
            if(nums[i] > nums[pos])
            {
                swap(nums[i], nums[pos]);
                break;
            }
    }
};