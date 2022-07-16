class Solution {
public:
    string decodeString(string s) {
        
        stack<int> freq;
        stack<string> strs;
        string cur = "";
        
        int i = 0;
        
        while(i < s.length())
        {
            auto c = s[i];
            if(c >= '0' && c <= '9')
            {
                int x = 0;
                while(i < s.length() && s[i] >= '0' && s[i] <= '9')
                {
                    x *= 10;
                    x += s[i] - '0';
                    i++;
                }
                i--;
                freq.push(x);
            }
                
                
            else if(c == '[')
            {
                strs.push(cur);
                cur = "";
            }
            else if(c == ']')
            {
                int count = freq.top();
                freq.pop();
                string prev = strs.top();
                strs.pop();
                while(count--)
                {
                    prev += cur;
                }
                cur = prev;
            }
            else 
                cur += c;
            i++;
            
        }
        return cur;
    }
};