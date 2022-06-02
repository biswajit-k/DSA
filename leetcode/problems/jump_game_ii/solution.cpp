class Solution {
public:

    
    int jump(vector<int>& nums) {
        
        int n = nums.size(), pos = 0, ans = 0, max_reach = 0;
        
        while(max_reach < n - 1)
        {
            int cur_reach = max_reach;
            ans++;
            
            while(pos <= cur_reach)
            {
                max_reach = max(max_reach, nums[pos] + pos);
                pos++;
            }
            
        }
        
        return ans;
        
    }
};