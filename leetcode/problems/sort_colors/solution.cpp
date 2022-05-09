class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1, two = nums.size(), cur = 0;
        
        while(cur < two)
        {
            if(nums[cur] == 0)
            {
                zero++;
                swap(nums[zero], nums[cur]);
                cur++;
            }
            else if(nums[cur] == 1)
                cur++;
            else 
            {
                two--;
                swap(nums[cur], nums[two]);
            }
        }
        
    }
};