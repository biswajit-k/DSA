class Solution {
public:
    
    int vis[51][51];
    int ans = 0;
    
    int dfs(int i, int j, vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        if(i >= n || j >= m || i < 0 || j < 0 || !grid[i][j] || vis[i][j])
            return 0;
        vis[i][j] = 1;
        return 1 + dfs(i + 1, j, grid) + dfs(i -1, j, grid) + dfs(i, j + 1, grid) + dfs(i, j - 1, grid);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < 51; i++)
            for(int j = 0;j < 51; j++)
                vis[i][j] = 0;
        
        int n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!vis[i][j] && grid[i][j])
                    ans = max(ans, dfs(i, j, grid));
        
        return ans;
    }
};