class Solution {
    
public:
    
    int ary[21] = {};
    
    int numTrees(int n) {
        ary[0] = ary[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 0; j < i; j++)
                ary[i] += ary[j] * ary[i - j - 1];
        }
        return ary[n];
    }
};