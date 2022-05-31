class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        if(s.length() < k)
            return 0;
        
        bool taken[(1 << k) + 4];
        memset(taken, 0, sizeof(taken));
        
        int num = 0, len = 0;
        
        while(len < k)
        {
            num |= (s[s.length() - len - 1] - '0') << len;
            len++;
        }
        taken[num] = 1;
        
        for(int i = s.length() - k - 1; i > -1; i--)
        {
            num |= (s[i] - '0') << k;
            num >>= 1;
            taken[num] = 1;
        }
        
        for(int i = 0; i < 1 << k; i++)
            if(!taken[i])
                return 0;
        
        return 1;
        
    }
};