class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        unordered_map<int, long long> dp;
        sort(begin(arr), end(arr));
        
        for(auto& x: arr)   dp[x] = 1;
        
        for(int i = 0; i < size(arr); i++)
            for(int j = 0; j < i; j++)
                if(!(arr[i] % arr[j]) && dp.count(arr[i] / arr[j]))
                {
                    long long val = dp[arr[i]];
                    val = (val + (dp[arr[j]] * dp[arr[i] / arr[j]]) % mod) % mod;
                    dp[arr[i]] = val;
                }
                   
        long long ans = 0;
        for(auto& x: arr)
            ans = (ans + dp[x]) % mod;
        
        return ans;
    }
};