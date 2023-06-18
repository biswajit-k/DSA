class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 1; i < n; i++)
            ans = min(ans, nums[i] - nums[i - 1]);
        return ans;
    }
};