class Solution {
public:
    
    vector<vector<string>> ans;
    
    bool check(int row, int col, vector<string>& grid)
    {
        int n = grid.size();
        
        for(int i = 0; i < n; i++)
            if(grid[row][i] == 'Q' || grid[i][col] == 'Q')
                return 0;
        
        for(int i = 0; row - i > - 1 && col - i > -1; i++)
            if(grid[row - i][col - i] == 'Q')
                return 0;
        for(int i = 0; row + i < n && col - i > -1; i++)
            if(grid[row + i][col - i] == 'Q')
                return 0;
        
        return 1;
    }
    
    void doit(int row, int col, vector<string>& grid, int n)
    {
        if(col == n)
        {
            ans.push_back(grid);
            return;
        }
        
        if(check(row, col, grid))
        {
            grid[row][col] = 'Q';
            doit(0, col + 1, grid, n);
            grid[row][col] = '.';
        }
        
        if(row < n - 1)
            doit(row + 1, col, grid, n);
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> grid(n, string(n, '.'));
        
        doit(0, 0, grid, n);
        return ans;
        
    }
};
