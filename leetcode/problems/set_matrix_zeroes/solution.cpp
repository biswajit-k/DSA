class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), isr = 0, isc = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && !matrix[i][j]) isr = 1;
                if(j == 0 && !matrix[i][j]) isc = 1;
                if(!matrix[i][j])
                    matrix[i][0] = 0, matrix[0][j] = 0;
            }
        }
        for(int i = 1; i < n ;i++)
            if(!matrix[i][0])
                for(int j = 0; j < m; j++)  matrix[i][j] = 0;
        for(int i = 1; i < m ;i++)
            if(!matrix[0][i])
                for(int j = 0; j < n; j++)  matrix[j][i] = 0;
        if(isr)
            for(int i = 0; i < m; i++)  matrix[0][i] = 0;
        if(isc)
            for(int i = 0; i < n; i++)  matrix[i][0] = 0;
    }
};