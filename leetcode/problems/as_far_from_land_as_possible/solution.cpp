class Solution {
public:

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool is_valid(int x, int y, int n) {
        return (min(x, y) >= 0 && max(x, y) < n);
    }


    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size(), ans = 0, dis = 1;
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1)
                    q.push({i, j});

        if(q.size() == n * n || q.empty())
            return -1;

        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto [x, y] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++)
                {
                    int xx = x + dx[j], yy = y + dy[j];
                    if(is_valid(xx, yy, n) && grid[xx][yy] == 0)
                    {
                        ans = dis;
                        grid[xx][yy] = 1;
                        q.push({xx, yy});
                    }
                }

            }
            dis++;
        }

        return ans;
    }
};