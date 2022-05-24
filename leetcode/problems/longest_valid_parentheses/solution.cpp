class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.length(), ans = 0;
        vector<int> dp(n, 0);
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                st.push(i);
            else if(!st.empty())
            {
                int pos = st.top();
                st.pop();
                dp[i] = i - pos + 1 + dp[(pos < 1 ? 0 : pos - 1)];
                ans = max(ans, dp[i]);
            }
        }
        
        return ans;
    }
};