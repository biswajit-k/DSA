class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        
        int l = 0;
        for(int i = 0; i < n; i++)
        {
            
            int req_rem = 0, j = i;
            for(; j < n && nums[j] <= threshold && (nums[j] % 2 == req_rem); j++, req_rem = 1 - req_rem);
            l = max(l, j - i);
        }
        return l;
    }
};