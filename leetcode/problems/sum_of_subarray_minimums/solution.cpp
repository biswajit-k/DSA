class Solution {
public:

    int sumSubarrayMins(vector<int>& arr) {
        
        const int mod = 1e9 + 7;
        
        stack<int> st;
        int n = arr.size();
        long long ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                int idx = st.top(), left = idx + 1, right = 1;
                st.pop();
                
                if(!st.empty())
                    left = idx - st.top();
                
                right = i - idx;
                
                ans = (ans + (left * right) % mod * 1ll * arr[idx]) % mod;
                
            }
            
            st.push(i);
        }
        
        while(size(st) > 1)
        {
            int idx = st.top();
            st.pop();
            ans = (ans + arr[idx] * 1ll * ((idx - st.top()) * (n - idx)) % mod) % mod;
        }
        
        int idx = st.top();
        ans = (ans + arr[idx] * 1ll * ((idx + 1) * (n - idx)) % mod) % mod;
        
        return ans;
        
    }
};