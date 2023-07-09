class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int l1 = 1, l2 = 1, ans = 1;
        
        for(int i = 1; i < n; i++)
        {
            int tl1 = l1, tl2 = l2;
            l1 = max(nums1[i - 1] <= nums1[i] ? 1 + tl1 : 1, nums2[i - 1] <= nums1[i] ? tl2 + 1 : 1);
            l2 = max(nums1[i - 1] <= nums2[i] ? 1 + tl1 : 1, nums2[i - 1] <= nums2[i] ? tl2 + 1 : 1);
            ans = max({ans, l1, l2});
        }
        
        return ans;
    }
};