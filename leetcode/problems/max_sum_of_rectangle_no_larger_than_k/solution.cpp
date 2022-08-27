class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int x) {
        
        int n = matrix.size(), m = matrix[0].size();
        
        for(int i = 0; i < n; i++)
            for(int j = 1; j < m; j++)
                matrix[i][j] += matrix[i][j - 1];
        
        int ans = -1e7;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                set<int> st;
                int c_sum = 0;
                for(int k = 0; k < n; k++)
                {
                    int s1 = (i >= 0 ? matrix[k][i] : 0);
                    int s2 = (j >= 1 ? matrix[k][j - 1] : 0);
                    c_sum += s1 - s2;
                    // cout << c_sum;
                    auto it = st.lower_bound(c_sum - x);
                    if(it != st.end())
                        ans = max(ans, c_sum - *it);
                    if(c_sum <= x)  ans = max(ans, c_sum);
                    st.insert(c_sum);
                }
            }
        }
        
        return ans;
    }
};