class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.size();

        vector<int> dp1(n, 0), dp2(n, 0);

        for(int j = 0; j < n; j++)
        {
            dp2[j] = 0;
            for(int i = j - 1; i > -1; i--)
            {
                dp2[i] = min(1 + dp1[i], 1 + dp2[i + 1]);
                if(s[i] == s[j])
                    dp2[i] = min(dp2[i], dp1[i + 1]);
            }
            swap(dp1, dp2);
        }

        return dp1[0];
    }
};