class Solution {
public:
    
    static constexpr int dx[] = {1, -1, 0, 0};
    static constexpr int dy[] = {0, 0, 1, -1};
    
    void dfs(int x, int y, vector<vector<char>>& grid)
    {
        grid[x][y] = '0';
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx > -1 && nx < grid.size() && ny > -1 && ny < grid[0].size() && grid[nx][ny] == '1')
                dfs(nx, ny, grid);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        int islands = 0;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    islands++;
                }
        
        return islands;
        
    }
};