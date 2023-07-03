class Solution {
public:
    
    int sumImbalanceNumbers(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> left(n + 2, -1), right(n + 2, n);
        vector<int> ans(n);

        for(int i = 0; i < n; i++)
        {
            ans[i] = i - left[nums[i] + 1];
            left[nums[i]] = i;
        }
        for(int i = n - 1; i > -1; i--)
        {
            int idx = min(right[nums[i]], right[nums[i] + 1]);
            ans[i] *= idx - i;
            right[nums[i]] = i;
        }
        
        int res = accumulate(begin(ans), end(ans), 0) - n * (n + 1) / 2;
        return res;
    }
};