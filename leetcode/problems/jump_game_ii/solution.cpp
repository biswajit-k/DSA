class Solution {
public:
    
    
    int doit(vector<int>& nums, vector<int>& steps, int pos)
    {
        if(pos >= nums.size() - 1)
            return 0;
        if(steps[pos] != -1)
            return steps[pos];
        
        int low = 1999999;
        for(int i = 1; i <= nums[pos]; i++)
            low = min(low, doit(nums, steps, pos + i));
        
        return steps[pos] = (1 + low);
    }
        
    
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> steps(n, -1);
        
        return doit(nums, steps, 0);
        
    }
};