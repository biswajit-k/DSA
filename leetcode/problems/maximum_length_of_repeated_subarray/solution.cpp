class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        if(nums2.size() > nums1.size())
            swap(nums1, nums2);

        int n = nums1.size(), m = nums2.size();
        vector<int> dp(m, 0), sub(m, 0);

        for(int i = 0; i < n; i++)
        {
            for(int j = m - 1; j > -1; j--)
            {
                int prev = j ? sub[j - 1] : 0;
                sub[j] = nums1[i] == nums2[j] ? 1 + prev : 0;
            }
            for(int j = 0; j < m; j++)
                dp[j] = max({sub[j], dp[j], (j ? dp[j - 1] : 0)});
        }

        return dp[m - 1];

    }
};