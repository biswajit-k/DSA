class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();

        int one_zero_length = 0, no_zero_length = 0, ans = 0, curr_one_zero_length, curr_no_zero_length;

        for(int i = 0; i < n; i++)
        {
            curr_one_zero_length = 1 + (nums[i] ? one_zero_length : no_zero_length);
            curr_no_zero_length = nums[i] ? no_zero_length + 1 : 0;

            ans = max({ans, curr_one_zero_length - 1, curr_no_zero_length - 1});
            one_zero_length = curr_one_zero_length;
            no_zero_length = curr_no_zero_length;
        }

        return ans;
    }
};