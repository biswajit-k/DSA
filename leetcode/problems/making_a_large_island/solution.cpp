class Solution {

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

public:

    int dfs(int x, int y, int grp, vector<vector<int>>& grid) {

        grid[x][y] = grp;
        int sz = 1, n = grid.size();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(is_valid(nx, ny, n) && grid[nx][ny] != 0 && grid[nx][ny] != grp)
                sz += dfs(nx, ny, grp, grid);
        }

        return sz;
    }

    bool is_valid(int x, int y, int n) {
        return max(x, y) < n && min(x, y) >= 0;
    }

    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size(), ans = 0;

        int grp = 2;
        unordered_map<int, int> grp_sz;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1)
                {
                    grp_sz[grp] = dfs(i, j, grp, grid);
                    grp++;
                }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 0)
                {
                    unordered_set<int> grps;
                    for(int k = 0; k < 4; k++)
                    {
                        int x = i + dx[k], y = j + dy[k];
                        if(is_valid(x, y, n))
                            grps.insert(grid[x][y]);
                    }
                    int sz = 1;
                    for(auto grp: grps)
                        sz += grp_sz[grp];
                    ans = max(ans, sz);
                }

        return (ans ? ans : n * n);
    }
};