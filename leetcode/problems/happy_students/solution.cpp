class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        int ways = 0;
        if(nums[0] > 0)
            ways++;
        
        for(int i = 0; i < n; i++)
        {
            if(i + 1 > nums[i] && (i == n - 1 || i + 1 < nums[i + 1]))
                ways++;
        }
        
        return ways;
    }
};