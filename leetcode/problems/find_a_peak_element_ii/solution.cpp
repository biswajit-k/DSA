class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        int l = 0, r = m - 1;

        while(l < r)
        {
            int mid = l + (r - l) / 2;

            int row = 0;
            for(int i = 0; i < n; i++)
                if(mat[i][mid] > mat[row][mid])
                    row = i;
            
            if(mat[row][mid] > mat[row][mid + 1])
                r = mid;
            else 
                l = mid + 1;
        }

        int row = 0;
        for(int i = 0; i < n; i++)
            if(mat[i][l] > mat[row][l])
                row = i;

        return {row, l};
    }
};