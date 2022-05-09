class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;
        
        while(l < h)
        {
            int mid = (l + h) / 2;
            // mid will always be less than h
            if(mid % 2 == 0)
            {
                if(nums[mid] != nums[mid + 1])  h = mid;
                else l = mid + 1;
            }
            else 
            {
                if(nums[mid] == nums[mid + 1])  h = mid;
                else l = mid + 1;
            }
        }
        return nums[l];
    }
};