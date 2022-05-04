class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int l = 0, r = (int)nums.size() - 1, operations = 0;
        
        while(l < r)
        {
            int cur = nums[l] + nums[r];
            if(cur == k)
                l++, r--, operations++;
            else if(cur < k)
                l++;
            else r--;
        }
        
        return operations;
    }
};