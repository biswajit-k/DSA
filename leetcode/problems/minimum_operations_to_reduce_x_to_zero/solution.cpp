class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        partial_sum(begin(nums), end(nums), begin(nums));
        
        int n = nums.size(), s = 0, ans = n + 1, req = nums.back() - x;
        
        if(req == 0)
            return n;
        
        for(int i = 0; i < n; i++)
        {
            while(s < i && (nums[i] - (s > 0 ? nums[s - 1] : 0) > req))
                s++;
            if(nums[i] - (s > 0 ? nums[s - 1] : 0) == req)
                ans = min(ans, n - i + s - 1);
        }
       
        return (ans == n + 1 ? -1 : ans);
        
    }
};