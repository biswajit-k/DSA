class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int tot[k];
        memset(tot, 0, sizeof(tot));
        for(int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
        tot[0]++;
        for(int i = 0; i < nums.size(); i++)
            if(abs(nums[i]) % k == 0)   tot[0]++;
            else
                tot[(nums[i] >= 0 ? nums[i] % k : (k - abs(nums[i]) % k))]++;
        
        int ans = 0;
        for(int i = 0; i < k; i++)
            ans += (tot[i] * (tot[i] - 1)) / 2;
        
        return ans;
        
    }
};