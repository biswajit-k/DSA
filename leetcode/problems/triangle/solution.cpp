class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    int dp[300][300];
    dp[1][1]=triangle[0][0];
    for(int i=2;i<=(int)triangle.size();i++)
    {
        for(int j=1;j<=triangle[i-1].size();j++)
        {
            if(j==1)
                dp[i][j]=triangle[i-1][0]+dp[i-1][j];
            else if(j==triangle[i-1].size())
                dp[i][j]=dp[i-1][j-1]+triangle[i-1][j-1];
            else 
            {
                dp[i][j]=triangle[i-1][j-1]+min(dp[i-1][j-1],dp[i-1][j]);
            }
        }
    }
    int minval=10000000;
    for(int i=1;i<=triangle.size();i++)
        minval=min(minval,dp[triangle.size()][i]);
    return minval;
}
};