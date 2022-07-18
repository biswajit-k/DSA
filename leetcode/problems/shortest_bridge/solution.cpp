class Solution {
public:
    
    queue<pair<int, int>> q;
    int vis[102][102];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    void dfs(int x, int y, vector<vector<int>>& grid)
    {
        int n = grid.size();
        vis[x][y] = 1;
        q.push({x, y});
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx > -1 && ny > -1 && nx < n && ny < n && !vis[nx][ny] && grid[nx][ny])
                dfs(nx, ny, grid);
        }
    }
        
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(vis, 0, sizeof(vis));
        
        bool found = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            if(grid[i][j])
            {
                dfs(i, j, grid);
                found = 1;
                break;
            }
            if(found)   break;
        }
            
        
        int step = 0;
        while(!q.empty())
        {
            int sz = size(q);
            for(int i = 0; i < sz; i++)
            {
                auto [x, y] = q.front();
                q.pop();
                for(int j = 0; j < 4; j++)
                {
                    int nx = x + dx[j], ny = y + dy[j];
                    
                    if(nx > -1 && ny > -1 && nx < n && ny < n && !vis[nx][ny])
                    {
                        vis[nx][ny] = 1;
                        if(grid[nx][ny])
                            return step;
                        q.push({nx, ny});
                    }
                    
                }
            }
            step++;
        }
        
        return 0;
        
    }
};