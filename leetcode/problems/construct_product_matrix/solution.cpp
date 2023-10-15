class Solution {
public:
    typedef long long llint;
    
    llint mod_pow(int x, int n, int M) {
        if(n == 0)
            return 1;
        
        llint res = mod_pow(x, n / 2, M);
        
        res = (res * res) % M;
        if(n % 2)
            res = (res * x) % M;
        
        return res;
    }
    
    int mod_inv(int A, int M)
{
    int m0 = M;
    int y = 0, x = 1;
 
    if (M == 1)
        return 0;
 
    while (A > 1) {
        // q is quotient
        int q = A / M;
        int t = M;
 
        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}
    
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<int> f = {3, 5, 823}, tf = {0, 0, 0};
        llint tp = 1;
        const int M = 12345;
        
        vector<vector<array<int, 3>>> factors(n, vector<array<int, 3>>(m));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                for(int k = 0; k < 3; k++)
                {
                    int c = 0;
                    while(grid[i][j] % f[k] == 0)
                    {
                        c++;
                        grid[i][j] /= f[k];
                    }
                    factors[i][j][k] = c;
                    tf[k] += c;
                    
                }
                tp = (tp * 1LL * grid[i][j]) % M;
            }
        
        // cout << tp << '\n';
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                bool contains_m = true;
                for(int k = 0; k < 3; k++)
                    if(tf[k] - factors[i][j][k] < 1)
                        contains_m = false;
                
                if(contains_m)
                    grid[i][j] = 0;
                else 
                {
                    llint res = tp;
                    for(int k = 0; k < 3; k++)
                        res = (res * mod_pow(f[k], tf[k] - factors[i][j][k], M)) % M;
                    
                    res = (res * mod_inv(grid[i][j], M)) % M;
                    grid[i][j] = res;
                }
            }
        }
        
        return grid;
    }
};