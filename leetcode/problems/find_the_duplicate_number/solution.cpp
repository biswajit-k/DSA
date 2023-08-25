class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = nums[0], fast = nums[nums[0]];

        while(nums[slow] != nums[fast])
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        
        while(nums[slow] != nums[fast])
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return nums[slow];
    }
};

/*

0 -> 1 -> 3 -> 2 -> 4
                |<-|

s = 4
f = 4

*/