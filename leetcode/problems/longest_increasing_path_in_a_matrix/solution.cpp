class Solution {
public:
    
    int ans, n, m;
    int dp[201][201];
    
    
    bool doit(int x, int y, vector<vector<int>>& matrix)
    {
        bool change = 0;
        for(int i = -1; i <= 1; i++)
            for(int j = -1; j <= 1; j++)
                if(abs(i) != abs(j))
                {
                    int nx = x + i, ny = y + j;
                    if(nx > -1 && nx < n && ny > -1 && ny < m)
                    {
                        if(matrix[nx][ny] > matrix[x][y] && dp[nx][ny] + 1 > dp[x][y])
                        {
                            dp[x][y] = dp[nx][ny] + 1;
                            change = 1;
                        }
                    }
                        
                } 
        return change;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        memset(dp, 0, sizeof(dp));
        ans = 0;
        n = matrix.size(), m = matrix[0].size();
        
        bool change = 1;
        
        while(change)
        {
            change = 0;
            for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                change |= doit(i, j, matrix);
        
        for(int i = n - 1; i > -1; i--)
            for(int j = m - 1; j > -1; j--)
                change |= doit(i, j, matrix);
            
        }
        
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                    ans = max(ans, dp[i][j]);
        
        return ans + 1;
    }
};