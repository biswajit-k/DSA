class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int l = 0, r = nums.size() - 1;

        while(l < r) 
        {
            int m = (l + r) / 2;

            if(nums[m] >= nums[l] && nums[m] <= nums[r])
                l = m + 1;
            else if(nums[m] >= nums[r] && nums[m] <= nums[l])
                r = m;
            else if(nums[m] >= nums[l] && nums[m] >= nums[r])
            {
                if(nums[m + 1] > nums[m])
                    l = m + 1;
                else 
                    r = m;
            }
            else 
                l = m + 1;

        }

        return l;
    }
};