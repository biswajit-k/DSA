class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        
        vector<int> ones(count(begin(nums), end(nums), 1));
        for(int i = 0, j = 0; i < nums.size(); i++)
            if(nums[i] == 1)
                ones[j++] = (i);

        int ans = 1e9, curr_ans = 0;

        for(int i = 0; i < k; i++)
            curr_ans += abs(ones[i] - ones[k / 2]) - abs(i - k / 2);

        
        ans = curr_ans;
        for(int i = k, mid_idx = k / 2 + 1; i < ones.size(); i++, mid_idx++)
        {
            curr_ans += ones[i] - ones[mid_idx] - (ones[mid_idx - 1] - ones[i - k]) + (ones[mid_idx] - ones[mid_idx - 1]) * (k / 2 * 2 - k + 1);
            ans = min(ans, curr_ans);
        }

        return ans;
    }
};