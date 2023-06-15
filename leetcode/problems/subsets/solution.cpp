class Solution {
public:

    vector<vector<int>> ans;

    void helper(int idx, vector<int>& nums, vector<int>& res) {

        if(idx == nums.size())
        {
            ans.push_back(res);
            return;
        }
        helper(idx + 1, nums, res);
        res.push_back(nums[idx]);
        helper(idx + 1, nums, res);
        res.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> res;
        helper(0, nums, res);

        return ans;
    }
};