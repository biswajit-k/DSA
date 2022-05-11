class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int r = 0, c = 0, n = matrix.size(), m = matrix[0].size();
        
        for(int i = 0; i < n; i++)
            if(!matrix[i][0])   r = 1;
        for(int i = 0; i < m; i++)
            if(!matrix[0][i])   c = 1;
        
        
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
                if(!matrix[i][j])
                {
                    matrix[0][j] = 0; matrix[i][0] = 0;
                }
                    
        
        for(int i = 1; i < n ; i++)
            for(int j = 1; j < m; j++)
                if(!matrix[0][j] || !matrix[i][0])  matrix[i][j] = 0;
        
        if(r)
            for(int i = 0; i < n; i++)  matrix[i][0] = 0;
        if(c)   for(int i = 0; i < m; i++)  matrix[0][i] = 0;
        
    }
};