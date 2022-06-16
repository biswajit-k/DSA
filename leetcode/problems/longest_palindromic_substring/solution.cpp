class Solution {
public:
    
    string longestPalindrome(string s) {
        
        int n = s.length(), start = 0, len = 1;
        vector<bool> dp(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            dp[i] = 1;
            
            for(int j = 0; j < i; j++)
            {
                if(s[i] == s[j] && dp[j + 1])
                {
                    dp[j] = 1;
                    if(i - j + 1 > len)
                    {
                        len = i - j + 1;
                        start = j;
                    }
                    
                }
                else 
                    dp[j] = 0;
            }
                
        }
        
        return s.substr(start, len);
        
    }
};