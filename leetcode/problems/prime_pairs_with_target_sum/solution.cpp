class Solution {
public:
    
    typedef long long llint;
    
    void seieve(vector<bool>& is_prime) {
        
        int n = is_prime.size() - 1;
        for(llint i = 2; i * i <= n; i++)
            if(is_prime[i])
                for(int j = 2 * i; j <= n; j += i)
                    if(is_prime[j])
                        is_prime[j] = false;
        
    }
    
    
    vector<vector<int>> findPrimePairs(int n) {
        
        vector<bool> is_prime(n + 1, true);
        
        seieve(is_prime);
    
        vector<vector<int>> ans;
        for(int i = 2; i <= n / 2; i++)
            if(is_prime[i] && is_prime[n - i])
                ans.push_back({i, n - i});
        
        return ans;
    }
    
};