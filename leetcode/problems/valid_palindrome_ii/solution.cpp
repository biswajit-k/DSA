class Solution {
public:
    
    bool check(string& s, int i, int j)
    {
        while(i < j)
            if(s[i] != s[j])
                return 0;
            else 
                i++, j--;
        return 1;
    }
    
    bool validPalindrome(string s) {
        
        int i = 0, j = s.length() - 1;
        bool po = 1;
        
        while(i < j)
        {
            if(s[i] != s[j])
            {
                po &= (check(s, i + 1, j) || check(s, i, j - 1));
                break;
            }
            i++;
            j--;
        }
            
        
        return po;
        
    }
};