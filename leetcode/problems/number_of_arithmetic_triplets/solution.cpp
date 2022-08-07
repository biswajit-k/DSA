
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
                if(nums[j] - nums[i] == diff && count(begin(nums) + j + 1, end(nums), diff + nums[j]))
                    ans++;
        }

        return ans;
    }
};