class Solution {
public:
    bool sumGame(string num) {
        int l = 0, r = 0, sl = 0, sr = 0, n = num.length();
        for(int i = 0; i < num.length(); i++)
        {
            if(i < n / 2)
            {
                if(num[i] == '?')   l++;
                else sl += num[i] - '0';
            }
            else 
            {
                if(num[i] == '?')   r++;
                else sr += num[i] - '0';
            }
        }
        
        if((l + r) % 2 == 1)
                return true;
        
        if((l - r) / 2 * 9 == (sr - sl))
                return false;
        return true;
        
    }
};