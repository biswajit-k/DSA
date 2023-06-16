class Solution {
public:

    vector<vector<int>> ans;

    void helper(int idx, vector<int>& nums, vector<int>& res) {

        ans.push_back(res);

        for(int i = idx; i < nums.size(); i++)
        {
            res.push_back(nums[i]);
            helper(i + 1, nums, res);
            res.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> res;
        helper(0, nums, res);

        return ans;
    }
};