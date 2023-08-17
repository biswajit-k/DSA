class Solution {
public:

    typedef pair<int, int> cell;

    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    bool is_valid(int x, int y, vector<vector<bool>>& vis) {
        if(min(x, y) < 0 || x >= vis.size() || y >= vis[0].size() || vis[x][y])
            return false;
        return true;            
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        queue<cell> q;

        // push all 0's into the queue for multi-source BFS
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mat[i][j] == 0)
                {
                    q.push({i, j});
                    vis[i][j] = true;
                }

        // stores current distance from 0's
        int dis = 0;

        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                // pick the current cell and move in all 4 directions
                auto [x, y] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++)
                {
                    int ny = y + dy[j], nx = x + dx[j];
                    // check if this position lies inside grid and not yet visted
                    if(is_valid(nx, ny, vis))
                    {
                        vis[nx][ny] = true;
                        mat[nx][ny] = dis + 1;
                        q.push({nx, ny});
                    }
                }

            }

            dis++;
        }

        return mat;
    }
};