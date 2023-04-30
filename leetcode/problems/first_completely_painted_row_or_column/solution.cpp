class Solution {
public:
     typedef pair<int, int> pii;
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, pii> mp;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                mp[mat[i][j]] = {i, j};
        
        vector<int> rcount(n, m), ccount(m, n);
        
        for(int i = 0; i < m * n; i++)
        {
            auto [r, c] = mp[arr[i]];
            if(--rcount[r] == 0 || --ccount[c] == 0)
                    return i;
        }
        return m * n - 1;        
    }
};