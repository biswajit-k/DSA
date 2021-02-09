class Solution {
public:
    
int minDistance(string word1, string word2) {
        int s1=word1.length(),s2=word2.length();

        int dp[s2+1][s1+1];
        dp[0][0]=0;
        for(int i=1;i<=s1;i++)
            dp[0][i]=i;
        for(int i=1;i<=s2;i++)          //[i][j]-> minimum steps req to form first i char o f word2 form word1 
            dp[i][0]=i;

        for(int i=1;i<=s2;i++)
            for(int j=1;j<=s1;j++)
                if(word1[j-1]==word2[i-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }        
                else
                {
                    dp[i][j]=1+min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
                }
        return dp[s2][s1];
    }

};