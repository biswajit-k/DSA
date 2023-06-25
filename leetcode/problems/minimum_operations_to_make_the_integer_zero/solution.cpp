class Solution {
public:
    
    int pop_count(long long x) {
        int c = 0;
        while(x)
        {
            if(x & 1)
                c++;
            x >>= 1;
        }
        return c;
    }
    
    int makeTheIntegerZero(int num1, int num2) {
        
        long long curr = num1;
        
        for(int i = 1; i < 50; i++)
        {
            curr -= num2;
            if(curr <= 0)
                return -1;
            
            int cnt = pop_count(curr);
            if(cnt <= i && curr >= i)
                return i;
        }
        
        return -1;
    }
};