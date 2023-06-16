class Solution {
public:

    vector<vector<int>> ans;

    void helper(int idx, vector<int>& res, vector<int>& nums) {

        ans.push_back(res);

        for(int i = idx; i < nums.size(); i++) {

            if(i == idx || nums[i] != nums[i - 1])
            {
                res.push_back(nums[i]);
                helper(i + 1, res, nums);
                res.pop_back();
            }
        }
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> res;
        sort(begin(nums), end(nums));
        helper(0, res, nums);

        return ans;
    }
};