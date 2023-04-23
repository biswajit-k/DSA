class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        int mi = *min_element(begin(nums), end(nums));
        
        if(mi == 1)
            return (n - count(begin(nums), end(nums), 1));
        
        int si = n + 1;
        
        for(int i = 0; i < n ;i++)
        {
            int gcd = nums[i];
            for(int j = i + 1; j < n; j++)
            {
                gcd = __gcd(gcd, nums[j]);
                if(gcd == 1)
                    si = min(si, j - i + 1);
            }
        }
        
        if(si == n + 1)
            return -1;
        
        return n + si - 2;
        
    }
};