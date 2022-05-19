class Solution {
public:
    string reverseWords(string s) {
        
        int pos = 0, i = 0, n = s.length();
        
        while(i < n)
        {
            int start;
            
            while(i < n && s[i] == ' ') i++;
            
            start = i;
            
            while(i < n && s[i] != ' ') i++;
            
            reverse(s.begin() + start, s.begin() + i);
            
            while(start < i)
            {
                swap(s[pos], s[start]);
                start++, pos++;
            }
            if(pos < n)
            {
                s[pos] = ' ';
                pos++;
            }
            
        }
        
        while(s.back() == ' ')  s.pop_back();
        
        reverse(s.begin(), s.end());
        
        return s;
        
    }
};