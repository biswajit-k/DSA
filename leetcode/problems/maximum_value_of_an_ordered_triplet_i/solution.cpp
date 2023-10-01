class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        
        long long ans = 0, res = 0;
        vector<int> left(n, -1), right(n, -1);
        
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], nums[i]);
            right[n - i - 1] = max(right[n - i], nums[n - i - 1]);
        }
        
        for(int i = 1; i < n - 1; i++)
        {
            res = (left[i - 1] - nums[i]) * 1LL * right[i + 1];
            ans = max(ans, res);
        }
        
        return ans;
    }
};