class Solution {
public:
    bool digitCount(string nums) {
        
        for(int i = 0; i < nums.length(); i++)
            if(count(nums.begin(), nums.end(), i + '0') != nums[i] - '0')
                return 0;
        return 1;
    }
};