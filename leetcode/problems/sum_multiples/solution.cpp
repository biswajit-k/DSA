class Solution {
public:
    int sumOfMultiples(int n) {
        
        vector<int> vis(n + 1, 0);
        vector<int> factors = {3, 5, 7};
        
        int ans = 0;
        for(auto& f: factors)
            for(int i = 1; i <= n; i++)
                    if(!vis[i] && (i % f == 0))
                    {
                        vis[i] = 1;
                        ans += i;
                    }
        
        return ans;
    }
};