class Solution {
public:    
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), steps = 0;
        
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        while(!q.empty())
        {
            steps++;
            int sz = q.size();
            
            for(int i = 0; i < sz; i++)
            {                    
                auto [u, v] = q.front();
                q.pop();

                if(u == n - 1 && v == n - 1)    return steps;
                
                for(int x = u - 1; x <= u + 1; x++)
                    for(int y = v - 1; y <= v + 1; y++)
                        if(x != u || y != v)
                            if(x > -1 && x < n && y > -1 && y < n)
                                if(grid[x][y] == 0)
                                {
                                    q.push({x, y});
                                    grid[x][y] = 1;
                                }

            }
            
        }
        
        return -1;
    }
};