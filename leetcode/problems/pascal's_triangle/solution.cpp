class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans(n);
        
        ans[0] = {1};
        for(int i = 1; i < n; i++)
        {
            ans[i].push_back(1);
            for(int j = 0; j + 1 < i; j++)
                ans[i].push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
            
            ans[i].push_back(1);
        }
        
        return ans;
    }
};