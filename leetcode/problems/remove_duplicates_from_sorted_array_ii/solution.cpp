class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();

        int counter = 1, curr_num = -1, len = 0;

        for(int j = 0; j < n; j++) 
        {

            if(nums[j] == curr_num)     counter++;
            else {
                counter = 1;
                curr_num = nums[j];
            }

            if(counter <= 2) {
                nums[len] = nums[j];
                len++;
            }

        }

        return len;
    }
};