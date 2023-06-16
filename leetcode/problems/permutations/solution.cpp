class Solution {
public:

    void helper(int pos, vector<int>& nums, vector<vector<int>>& res) {

        if(pos == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); i++)
        {
            swap(nums[i], nums[pos]);
            helper(pos + 1, nums, res);
            swap(nums[i], nums[pos]);
        }

    }


    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        helper(0, nums, res);

        return res;
    }
};