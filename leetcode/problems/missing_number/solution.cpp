class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int x = accumulate(begin(nums), end(nums), 0, [&](int a, int b){
            return a^b;}
        );
        
        for(int i = 0; i <= nums.size(); i++)
            x ^= i;
        
        return x;
        
    }
};