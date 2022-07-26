class Solution {
public:
    
    int b_search(vector<int>& nums, int x, bool upper = 0)
    {
        int l = 0, r = nums.size() - 1, pos = -1;
        
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            
            if(nums[mid] < x)
                l = mid + 1;
            else if(nums[mid] > x)
                r = mid - 1;
            else 
            {
                pos = mid;
                if(upper)   l = mid + 1;
                else    r = mid - 1;
            }
        }
        
        return pos;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int f = b_search(nums, target), s = b_search(nums, target, 1);
        
        return {f, s};
    }
};