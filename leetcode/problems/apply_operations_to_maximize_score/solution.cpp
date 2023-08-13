class Solution {
    
public:
    
    const int N = 1e5, mod = 1e9 + 7;

    long long mod_expo(int x, int n) {
        
        if(n == 0)
            return 1;
        
        long long res = mod_expo(x, n / 2);
        
        long long ans = (res * 1LL * res) % mod;
        if(n % 2 == 1)
            ans = (ans * 1LL * x) % mod;
        
        return ans;
    }
    
    int maximumScore(vector<int>& nums, int k) {

        static vector<int> score;
        
        if(score.empty())
        {
            score.resize(N + 1);
            for(int i = 2; i <= N; i++)
            {
                if(score[i] > 0)
                    continue;
                for(int j = i; j <= N; j += i)
                    score[j]++;
            }
        }
        
        int n = nums.size();
        
        stack<int> st;
        vector<int> left_idx(n);
        vector<pair<int, long long>> num_range;
        
        
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && score[nums[st.top()]] < score[nums[i]])
            {
                int j = st.top();
                st.pop();
                
                num_range.push_back({nums[j], (j - left_idx[j] + 1) * 1LL * (i - j)});
            }
            
            left_idx[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        
        while(!st.empty())
        {
            int i = st.top();
            st.pop();
            num_range.push_back({nums[i], (i - left_idx[i] + 1) * 1LL * (n - i)});
        }
        
        sort(begin(num_range), end(num_range), greater<pair<int, long long>>());
        
        long long ans = 1;
        
        for(int i = 0; i < num_range.size() && k > 0; i++)
        {
            int take = min((long long)k, num_range[i].second);
            
            // cout << num_range[i].first << ' ' << num_range[i].second << '\n';
            
            ans = (ans * mod_expo(num_range[i].first, take)) % mod;
            // cout << ans << '\n';
            k -= take;
        }
        
        return ans;
    }
};