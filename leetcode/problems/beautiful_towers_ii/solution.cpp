class Solution {
public:
    
    typedef long long llint;
    
    long long maximumSumOfHeights(vector<int>& H) {
        
        int n = H.size();
        
        // idx smaller on the left and right
        vector<int> left(n, -1), right(n, n);
        
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && H[st.top()] >= H[i])
            {
                int idx = st.top();
                st.pop();
                right[idx] = i;
            }
            if(!st.empty())
                left[i] = st.top();
            
            st.push(i);
        }
        
        vector<llint> dp_left(n, 0), dp_right(n, 0);
        
        for(int i = 0; i < n; i++)
            dp_left[i] = H[i] * 1LL * (i - left[i]) + (left[i] == -1 ? 0 : dp_left[left[i]]);

        for(int i = n - 1; i > -1; i--)
            dp_right[i] = H[i] * 1LL * abs(i - right[i]) + (right[i] == n ? 0 : dp_right[right[i]]);
        
        llint ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, dp_left[i] + dp_right[i] - H[i]);
        
        return ans;
    }
};