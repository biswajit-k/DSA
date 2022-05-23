class Solution {
public:
    
    int ans = 0;
    
    int doit(string& s, int l, int r)
    {
        int c = 0;
        while(l > -1 && r < s.length() && s[l] == s[r])
            l--, r++, c++;
        return c;
    }
    
    int countSubstrings(string s) {
        
        for(int i = 0;i < s.length(); i++)
            ans += doit(s, i, i) + doit(s, i - 1, i);

        
        
        return ans;
    }
};