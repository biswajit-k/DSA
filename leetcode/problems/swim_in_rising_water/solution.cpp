class Solution {
public:

    typedef pair<int, pair<int, int>> cell;

    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {1, 0, 0, -1};

    bool is_valid(int x, int y, vector<vector<int>>& status) {
        if(min(x, y) < 0 || max(x, y) >= status.size())
            return 0;
        return status[x][y] < 2;
    }

    bool explore(int x, int y, int t, vector<vector<int>>& grid, vector<vector<int>>& status, priority_queue<cell>& pq) {
        if(x == grid.size() - 1 && y == grid.size() - 1)
            return 1;

        status[x][y] = 2;
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(is_valid(nx, ny, status))
            {
                if(grid[nx][ny] <= t)
                {
                    if(explore(nx, ny, t, grid, status, pq))
                        return t;
                }
                else if(status[nx][ny] == 0)
                {
                    pq.push({-grid[nx][ny], {nx, ny}});
                    status[nx][ny] = 1;
                }
            }
        }
        return 0;
    }

    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size(), t = 0;

        priority_queue<cell> pq;
        vector<vector<int>> status(n, vector<int>(n));

        // {elevation, x, y}
        pq.push({-grid[0][0], {0, 0}});
        status[0][0] = 1;

        while(!pq.empty())
        {
            while(-pq.top().first <= t)
            {
                auto [x, y] = pq.top().second;
                pq.pop();

                if(status[x][y] == 1)
                {
                    if(explore(x, y, t, grid, status, pq))
                        return t;
                }
            }

            t = -pq.top().first;
        }

        return -1;
    }
};