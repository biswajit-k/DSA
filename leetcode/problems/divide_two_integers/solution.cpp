class Solution {
public:
    int divide(int dividend, int divisor) {

        bool neg = ((dividend < 0) ^ (divisor < 0));
        long long curr = 1, count = 0, a = dividend, b = divisor, div;
        a = abs(a);
        b = abs(b);
        div = b;
        
        while(a >= div)
        {
            while(b < a)
                b <<= 1, curr <<= 1;
            while(b > a)
                b >>= 1, curr >>= 1;
            
            a -= b;
            count += curr;
        }
        
        if(count > INT_MAX && !neg)
            count = INT_MAX;
        
        
        return (neg ? -count : count);
        
    }
};