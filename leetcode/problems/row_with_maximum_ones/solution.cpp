class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size();
        int r = 0, cnt = count(begin(mat[0]), end(mat[0]), 1);
        
        for(int i = 0; i < n; i++)
        {
            int curr = count(begin(mat[i]), end(mat[i]), 1);
            if(curr > cnt)
                r = i, cnt = curr;
                
        }
            
        return {r, cnt};
    }
};