class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int ops = 0;
        int n = 1, a_or_b = a | b;

        while(n <= max(c, a_or_b))
        {
            if(c & n)
                ops += 1 - !!(a_or_b & n);
            else 
                ops += !!(a & n) + !!(b & n);

            n <<= 1;
        }

        return ops;
    }
};