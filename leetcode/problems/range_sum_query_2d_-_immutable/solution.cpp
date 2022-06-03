class NumMatrix {
public:
    
    int mat[201][201];
    int n, m;
    
    int take(int i, int j)
    {
        if(i < 0 || j < 0)
            return 0;
        else return mat[i][j];
    }
    
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        
        for(int i = 0; i < n ; i++)
            for(int j = 0; j < m; j++)
                mat[i][j] = take(i - 1, j) + take(i, j - 1) - take(i - 1, j - 1) + matrix[i][j];
        
    }
    
    int sumRegion(int i1, int j1, int i2, int j2) {
        return take(i2, j2) - take(i1 - 1, j2) - take(i2, j1 - 1) + take(i1 - 1, j1 - 1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */