class Solution {
public:
    
    int get_mx_digit(int x) {
        
        int mx = 0;
        while(x)
        {
            mx = max(mx, x % 10);
            x /= 10;
        }
        return mx;
    }
    
    int maxSum(vector<int>& nums) {
        
        int n = nums.size(), ans = -1;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
                if(get_mx_digit(nums[i]) == get_mx_digit(nums[j]))
                    ans = max(ans, nums[i] + nums[j]);
        }
        
        return ans;
    }
};