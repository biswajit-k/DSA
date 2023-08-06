class Solution {
public:
    
    const int inf = 1e8;
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    
    void set_sf(int i, int j, vector<vector<int>>& sf, int n) {
        
        int d = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        sf[i][j] = 0;
        
        while(!q.empty())
        {
            int sz = q.size();

            for(int i = 0; i < sz; i++)
            {
                auto [x, y] = q.front();
                q.pop();
                
                for(int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k], ny = y + dy[k];
                    if(max(nx, ny) < n && min(nx, ny) > -1 && sf[nx][ny] > d)
                    {
                        sf[nx][ny] = d;
                        q.push({nx, ny});
                    }
                }
            }
            d++;
        }
        
        
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        // vector<int> sf(n, inf);
        vector<vector<int>> sf(n, vector<int>(n, inf));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1)
                    set_sf(i, j, sf, n);
        
        int sf_path[n][n];
        
        cout << sf[n - 1][n - 1] << '\n';
        
        for(int i = 0; i < n; i++)  for(int j = 0; j < n; j++)  sf_path[i][j] = -inf;
        sf_path[0][0] = sf[0][0];
        priority_queue<tuple<int, int, int>> pq;
        pq.push({sf[0][0], 0, 0});
        
        while(!pq.empty())
        {
            auto [safety, x, y] = pq.top();
            pq.pop();

            if(safety < sf_path[x][y])
                continue;
            
            for(int k = 0; k < 4; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];
                if(max(nx, ny) < n && min(nx, ny) > -1 && sf_path[nx][ny] < min(sf[nx][ny], sf_path[x][y]))
                {
                    sf_path[nx][ny] = min(sf[nx][ny], sf_path[x][y]);
                    pq.push({sf_path[nx][ny], nx, ny});
                } 
            }
        }
        
        return sf_path[n - 1][n - 1];
        
    }
};