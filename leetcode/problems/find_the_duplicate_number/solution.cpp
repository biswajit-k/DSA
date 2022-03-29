class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int pos = 0, n = nums.size() - 1;
        
        while(pos < n)
        {
            while(nums[pos] != pos + 1)
            {
                if(nums[pos] == nums[nums[pos] - 1])
                    return nums[pos];
                swap(nums[pos], nums[nums[pos] - 1]);    
            }
            pos++;
        }
        return nums[n];
        
    }
};