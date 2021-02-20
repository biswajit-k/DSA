class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int ans=6000;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]>=nums[r])
            {
                ans=min(ans,nums[r]);
                l=mid+1;
                
            }
            else 
            {
                ans=min(ans,nums[mid]);
                r=mid-1;
            }
        }
        return ans;
    }
};