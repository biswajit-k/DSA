class Solution {
public:
    int fib(int n) {
        
        if(n == 0)  return 0;
        else if(n == 1) return 1;
                
        int fi = 0, se = 1;
        
        for(int i = 2; i <= n; i++)
        {
            int x = fi + se;
            fi = se;
            se = x;
        }
        
        return se;
    }
};