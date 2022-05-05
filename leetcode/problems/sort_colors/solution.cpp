class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = -1, h = nums.size(), i = 0;
        
        while(i < h)
        {
            if(nums[i] == 0)
            {
                l++; swap(nums[i], nums[l]);
                i++;
            }
                
            else if(nums[i] == 1)
                i++;
            else 
            {
                h--; swap(nums[h], nums[i]);
            }
                
            
        }
    }
};