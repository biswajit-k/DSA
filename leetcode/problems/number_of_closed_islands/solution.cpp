class Solution {
public:

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& marked) {

        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())  
            return -1;
        if(marked[i][j])    
            return 0;

        marked[i][j] = 1;

        if(grid[i][j])
            return 0;

        int top = dfs(i, j - 1, grid, marked);
        int bottom = dfs(i, j + 1, grid, marked);
        int left = dfs(i - 1, j, grid, marked);
        int right = dfs(i + 1, j, grid, marked);
        
        if(top == -1 || bottom == -1 || left == -1 || right == -1)
            return -1;

        return 1;
    }


    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> marked(n, vector<bool>(m, 0));

        int ans = 0;

        for(int i = 0; i < n;i++)
            for(int j = 0;j < m; j++)
                if(dfs(i, j, grid, marked) == 1)
                    ans++;

        return ans;
    }
};