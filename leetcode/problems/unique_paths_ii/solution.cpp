class Solution {
public:
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        if(grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return 0;
        
        int ways[n + 1][m + 1];
        memset(ways, 0, sizeof(ways));
        ways[0][0] = 1;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(i > 0 && !grid[i - 1][j])    ways[i][j] += ways[i - 1][j];
                if(j > 0 && !grid[i][j - 1])    ways[i][j] += ways[i][j - 1];
                    
            }
        
        return ways[n - 1][m - 1];
        
    }
};