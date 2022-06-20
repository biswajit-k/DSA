class Solution {
public:
    
    // {max_value, sum_of_non_leaf}
    pair<int, int> dp[41][42];
    
    pair<int, int> helper(int i, int j)
    {
        if(dp[i][j].first != -1)
            return dp[i][j];
        
        int mx_value = 0, sum = INT_MAX;
        
        for(int k = i; k < j; k++)
        {
            auto p1 = helper(i, k), p2 = helper(k + 1, j);
            int sm = p1.second + p2.second + p1.first * p2.first;
            if(sm < sum)
            {
                sum = sm;
                mx_value = max(p1.first, p2.first);
            }
        }
        
        return dp[i][j] = {mx_value, sum};
            
    }
    
    
    int mctFromLeafValues(vector<int>& arr) {
        
        int n = arr.size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i == j)
                    dp[i][i] = {arr[i], 0};
                else 
                    dp[i][j] = {-1, -1};
        
        return helper(0, n - 1).second;
        
    }
};