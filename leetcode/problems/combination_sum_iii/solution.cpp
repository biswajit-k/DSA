class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(int k, int n, vector<int> sol)
    {
        if(k == 0 && n == 0)
        {
            ans.push_back(sol);
            return;
        }
        if(k < 0 || n < 0)
            return;
        if(k && n)
        {
            int to = sol.empty() ? 9 : sol.back() - 1;
            for(int i = 1; i <= to; i++)
            {
                if(n - i < 0)
                    break;
                sol.push_back(i);
                helper(k - 1, n - i, sol);
                sol.pop_back();
            }
        }
            
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> sol;
        helper(k, n, sol);
        return ans;
    }
};