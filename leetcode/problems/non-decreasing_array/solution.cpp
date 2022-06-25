class Solution {
public:
    
    bool checkPossibility(vector<int>& nums) {
     
        int change = 0;
        for(int i = 0; i < nums.size() - 1 && change < 2; i++)
            if(nums[i] > nums[i + 1])
            {
                change++;
                if(i < 1 || nums[i + 1] >= nums[i - 1])    nums[i] = nums[i + 1];
                else nums[i + 1] = nums[i];
            }
            
        return change < 2;
    }
};