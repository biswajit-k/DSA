
class Solution {
public:
    
    int cnt[51][51][51];
    const int mod = 1e9 + 7;
    
    int helper(int n, int m, int moves, int x, int y)
    {
         if(x < 0 || y < 0 || x >= n || y >= m)
            return 1;
        if(moves == 0)
            return 0;
        if(cnt[x][y][moves] != -1)  return cnt[x][y][moves];
        
        int down = helper(n, m, moves - 1, x + 1, y);
        int up = helper(n, m, moves - 1, x - 1, y);
        int left = helper(n, m, moves - 1, x, y - 1);
        int right = helper(n, m, moves - 1, x, y + 1);
        
        return cnt[x][y][moves] = ((up + down) % mod + (left + right) % mod) % mod;
    }
    
    int findPaths(int n, int m, int moves, int x, int y) {

       for(int i = 0;i < n; i++) 
           for(int j = 0; j < m; j++)
               for(int k = 0; k < 51; k++)
                   cnt[i][j][k] = -1;
        
        return helper(n, m, moves, x, y);
    }
};
