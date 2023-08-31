class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        int n = nums.size();
        long long breaks = 0;

        for(int i = n - 2; i > -1; i--)
        {
            if(nums[i] <= nums[i + 1])
                continue;
            
            long long q = nums[i] / nums[i + 1], rem = nums[i] % nums[i + 1];
            breaks += q + (rem > 0) - 1;

            if(rem > 0)
            {
                long long a = ceil((nums[i + 1] - rem) / (double)(q + 1));
                nums[i] = nums[i + 1] - a;
            }
            else 
                nums[i] = nums[i + 1];
        }

        return breaks;
    }
};