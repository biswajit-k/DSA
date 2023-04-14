class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n = s.length();

        vector<vector<int>> lps(n, vector<int>(n, 0));
        for(int i = 0; i < n ;i++)
            lps[i][i] = 1;

        for(int j = 1; j < n; j++)
        {
            for(int i = j - 1; i > -1; i--)
            {
                if(s[i] == s[j])
                    lps[i][j] = 2 + lps[i + 1][j - 1];
                else 
                    lps[i][j] = max(lps[i + 1][j], lps[i][j - 1]);
            }
        }
    
        return lps[0][n - 1];
    }
};