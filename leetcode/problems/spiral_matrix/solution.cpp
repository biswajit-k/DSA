class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size();
        int x = 0, y = 0;

        vector<int> res;

        while(n > 0 && m > 0)
        {
            for(int i = 0; i < m; i++)
                res.push_back(mat[x][y++]);

            y--;    x++;
            if(--n == 0)    break;

            for(int i = 0; i < n; i++)
                res.push_back(mat[x++][y]);

            x--;    y--;
            if(--m == 0)  break;

            for(int i = 0; i < m; i++)
                res.push_back(mat[x][y--]);
            
            y++;    x--;
            if(--n == 0)    break;
            for(int i = 0; i < n; i++)
                res.push_back(mat[x--][y]);
            
            x++;    y++;
            if(--m == 0)    break;
        }
        
        return res;
    }
};