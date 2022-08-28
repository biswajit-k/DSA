class Solution {
public:
    
    void insertion(int i, int j, vector<vector<int>>& mat)
    {
        int n = mat.size(), m = mat[0].size();
        
        int p = 0;
        while(i + p < n && j + p < m)
        {
            int x = i + p, y = j + p;
            int key = mat[x][y];
            
            while(x > 0 && y > 0 && mat[x - 1][y - 1] > key)
            {
                mat[x][y] = mat[x - 1][y - 1];
                x--, y--;
            }
            
            mat[x][y] = key;
            p++;
        }
    }
    
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size();
        
        for(int i = n - 1; i > -1; i--)
            insertion(i, 0, mat);
        for(int i = 1; i < m; i++)
            insertion(0, i, mat);
        
        return mat;
    }
};