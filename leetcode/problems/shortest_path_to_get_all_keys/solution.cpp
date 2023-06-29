class Solution {

    const int inf = 1e8;

    struct Point {
        int x, y;

        Point(int a = 0, int b = 0) {
            x = a, y = b;
        }

    };

    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    unordered_map<char, Point> coordinates;

    bool is_valid(int& x, int& y, unordered_set<char>& not_available, vector<vector<bool>>& vis, vector<string>& grid) {
        if(min(x, y) >= 0 && x < grid.size() && y < grid[0].size())
        {
            if(grid[x][y] == '#' || (grid[x][y] <= 'Z' && grid[x][y] >= 'A' && not_available.count(grid[x][y] + 'a' - 'A')) || vis[x][y])
            return 0;
            return 1;
        }
        return 0;
    }

    int get_path_length(int x, int y, char final, unordered_set<char>& not_available, vector<string>& grid) {
        if(grid[x][y] == final)
            return 0;

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        q.push({x, y});
        vis[x][y] = true;

        int l = 1;

        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto [x, y] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int xx = x + dx[i], yy = y + dy[i];
                    if(is_valid(xx, yy, not_available, vis, grid))
                    {
                        if(grid[xx][yy] == final)   return l;
                        q.push({xx, yy});
                        vis[xx][yy] = true;
                    }
                }
            }
            l++;
        }

        return inf;
    }

public:

    int shortest_path(Point& start, string& keys, int pos, vector<string>& grid) {
        if(pos == keys.size())
            return 0;

        unordered_set<char> not_available(begin(keys) + pos, end(keys));

        int ans = inf;

        for(int i = pos; i < keys.length(); i++)
        {
            swap(keys[pos], keys[i]);

            int path_length = get_path_length(start.x, start.y, keys[pos], not_available, grid);
            int remaining_path_length = shortest_path(coordinates[keys[pos]], keys, pos + 1, grid);
            // cout << pos << ' ' << path_length << ' ' << remaining_path_length << '\n';
            ans = min(ans, path_length + remaining_path_length);

            swap(keys[pos], keys[i]);
        }

        return ans;
    }

    int shortestPathAllKeys(vector<string>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        Point start;
        string keys = "";

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '@')
                    start.x = i, start.y = j;
                else if(grid[i][j] <= 'z' && grid[i][j] >= 'a')
                    keys += grid[i][j], coordinates[grid[i][j]] = Point(i, j);
            }

        int len = shortest_path(start, keys, 0, grid);
        return (len >= inf ? -1 : len);
    }
};