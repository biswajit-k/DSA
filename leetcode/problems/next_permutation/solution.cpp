class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        if(n <= 1)
            return;
        
        int pos = n - 2;
        for(; pos > -1; pos--)
        {
            if(nums[pos] < nums[pos + 1])
                break;
        }
        if(pos == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        reverse(nums.begin() + pos + 1, nums.end());
        for(int i = pos + 1; i < n; i++)
            if(nums[i] > nums[pos])
            {
                swap(nums[i], nums[pos]);
                break;
            }
        
    }
};