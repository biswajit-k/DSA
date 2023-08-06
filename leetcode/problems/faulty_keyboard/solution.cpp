class Solution {
public:
    string finalString(string s) {
        int n = s.length();
        
        string res = "";
        for(int i = 0; i < n; i++)
        {
            if(s[i] != 'i')
                res += s[i];
            else 
                reverse(begin(res), end(res));
        }
        
        return res;
    }
};