class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     
        int pos = m, i = 0, j = 0;
        
        for(int k = 0; k < m + n; k++)
        {
            int x;
            if(i == m)
                x = nums2[j++];
            else if(j == n)
                x = nums1[i++];
            else if(nums1[i] < nums2[j])
                x = nums1[i++];
            else 
                x = nums2[j++];
            
            nums1[pos % (m + n)] = x;
            pos++;
        }
        
        rotate(nums1.rbegin(), nums1.rbegin() + n, nums1.rend());
        
    }
};