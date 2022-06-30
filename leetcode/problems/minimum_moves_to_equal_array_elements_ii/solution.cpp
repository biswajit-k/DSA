class Solution {
public:

    
    int minMoves2(vector<int>& nums) {
       
        sort(begin(nums), end(nums));
        int n = nums.size(), m = (n) / 2, ans = 0;
        
        
        for(int i = 0; i < n;i++)
                ans += abs(nums[i] - nums[m]);
        
        return ans;
    }
};