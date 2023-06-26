class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<pair<int, int>> new_nums;
        for(int i = 0; i < n;)
        {
            int cnt = 0, j = i;
            while(j < n && nums[j] == nums[i])
            {
                cnt++;
                j++;
            }
            new_nums.push_back({nums[i], cnt});
            i = j;
        }

        int m = new_nums.size();
        vector<int> dp(m);
        dp[m - 1] = new_nums[m - 1].first * new_nums[m - 1].second;
        
        for(int i = m - 2; i > -1; i--)
        {
            if(new_nums[i + 1].first == new_nums[i].first + 1)
            {
                int nxt = i + 2 < m ? dp[i + 2] : 0;
                dp[i] = max(new_nums[i].second * new_nums[i].first + nxt, dp[i + 1]);
            }
            else 
                dp[i] = new_nums[i].second * new_nums[i].first + dp[i + 1];
        }

        return dp[0];
    }
};