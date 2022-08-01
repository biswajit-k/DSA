class Solution {
public:
    
    #define llint long long
    
    int uniquePaths(int m, int n) {
        
        llint res = 1;
        llint top = max(n, m);
        
        for(int i = 1; i < min(n, m); i++, top++)
            res = res * top / i;
        
        return res;
    }
};