class Solution {
public:
    
    vector<int> ans;
    vector<vector<int>> res;
    // int dp[501][31];
    
    void helper(vector<int>& candidates, int target, int pos)
    {
        if(pos == -1)
            return;
        if(target == 0)
        {
            res.push_back(ans);
            return;
        }
        // if(dp[target][pos] != -1)
        if(target >= candidates[pos])
        {
            ans.push_back(candidates[pos]);
            helper(candidates, target - candidates[pos], pos);
            ans.pop_back();
        }
        helper(candidates, target, pos - 1);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        // for(int i = 0; i < 501; i++)
        //     for(int j = 0; j < 31; j++)
        //         dp[i][j] = -1;
        helper(candidates, target, size(candidates) - 1);
        return res;
    }
};