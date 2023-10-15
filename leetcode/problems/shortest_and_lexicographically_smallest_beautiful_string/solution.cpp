class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.length();
        
        int i = -1, r = 0;
        string ans = "";
        bool init = false;
        
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
            {
                string sub = s.substr(i, j - i + 1);
                if(count(begin(sub), end(sub), '1') == k && sub[0] == '1')
                {
                    if(init == false)
                    {
                        init = true;
                        ans = sub;
                    }    
                    else if(sub.length() < ans.length() || (sub.length() == ans.length() && sub < ans))
                        ans = sub;
                }
                
            }
        return ans;
    }
};