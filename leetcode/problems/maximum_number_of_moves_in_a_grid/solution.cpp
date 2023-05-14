class Solution {
public:
    
    int dx[3] = {-1, 0, 1};
    int dy[3] = {1, 1, 1};
    
    bool isvalid(int i, int j, int n, int m) {
        if(i < 0 || i >= n || j >= m)
            return 0;
        return 1;
    }
    
    int check(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        
        int n = grid.size(), m = grid[0].size();    
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        int res = 0;
        for(int k = 0; k < 3; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if(isvalid(x, y, n, m) && grid[x][y] > grid[i][j])
                res = max(res, 1 + check(x, y, grid, dp));
        }
        
        return dp[i][j] = res;
    }
    
    
    int maxMoves(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, check(i, 0, grid, dp));

        return ans;
    }
};