class Solution {
public:
    string smallestString(string s) {
        
        
        int n = s.length(), i = 0;
        if(count(begin(s), end(s), 'a') == n)
        {
            s.back() = 'z';
            return s;
        }
        
        while(i < n && s[i] == 'a') i++;
        
        while(i < n && s[i] != 'a') 
        {
            s[i]--;
            i++;
        }
        
        return s;
    }
};