class Solution {
public:
    
    bool isInt(string s, int sign = 1)
    {
        
        int i = 0; 
        if(sign && (s[i] == '+' || s[i] == '-'))  i++;
        if(i == s.length())
            return 0;
        for(; i < s.length(); i++)
            if(s[i] > '9' || s[i] < '0')
                return 0;
        return 1;
    }
    
    bool isDec(string s)
    {
        if(!s.empty() && (s[0] == '+' || s[0] == '-'))  s = s.substr(1);
        int n = s.length();
        if(n < 2)
            return 0;
        
        int dot = -1;
        
        for(int i = 0; i < n; i++)
            if(s[i] == '.')
            {
                dot = i;
                break;
            }
                
        if(dot == -1)   return 0;
        bool ok = 1;
        if(dot > 0)
            ok &= isInt(s.substr(0, dot));
        if(dot < n - 1)
            ok &= isInt(s.substr(dot + 1, n - dot), 0);
        
        return ok;
    }
    
    bool isNumber(string s) {
        
        int e = 0, n = s.length();
        
        for(; e < n; e++)
            if(s[e] == 'e' || s[e] == 'E')  break;
        
        if(e == n)
            return (isInt(s) || isDec(s));
        
        if(e == 0 || e == n - 1)
            return 0;
        
        return ((isDec(s.substr(0, e)) || isInt(s.substr(0, e))) && isInt(s.substr(e + 1, n - e)));
        
    }
};