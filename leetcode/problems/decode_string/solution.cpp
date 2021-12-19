class Solution {
public:
    
    string dec(string s, int& pos)
    {
        string cur = "";
        int freq = 0;
        while(pos < s.length())
        {
            if(s[pos] >= '0' && s[pos] <= '9')
            {
                freq = freq * 10 + (s[pos] - '0');
            }
            else if(s[pos] == '[')
            {
                string ans = dec(s, ++pos);
                for(int i = 0; i < freq; i++)
                        cur += ans;
                freq = 0;
                continue;
                
            }
            else if(s[pos] == ']')
            {
                pos++;
                break;
            }
            else
            {
                cur += s[pos];
            }
            
            
            pos++;
        }
        return cur;
        
        
        
    }
    
    string decodeString(string s) {
        int pos = 0;
        return dec(s, pos);
    }
};