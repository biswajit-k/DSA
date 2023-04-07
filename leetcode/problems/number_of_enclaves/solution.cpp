class Solution {
public:

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& marked) {

        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || marked[i][j])
            return 0;

        marked[i][j] = 1;
        if(!grid[i][j]) 
            return 0;

        int top = dfs(i, j - 1, grid, marked);
        int left = dfs(i - 1, j, grid, marked);
        int bottom = dfs(i, j + 1, grid, marked);
        int right = dfs(i + 1, j, grid, marked);

        return 1 + top + left + bottom + right;
    }


    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> marked(n, vector<bool>(m, 0));

        int total = 0, boundary = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j])
                    total++;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!marked[i][j] && (i * j == 0 || i == n - 1 || j == m - 1))
                    boundary += dfs(i, j, grid, marked);

        return total - boundary;
    }
};