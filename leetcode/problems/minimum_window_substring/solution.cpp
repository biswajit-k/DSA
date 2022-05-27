class Solution {
public:
    string minWindow(string s, string p) {
        int req[400], curr[400], m = p.size(), n = s.size();
        memset(req, 0, sizeof(req));
        memset(curr, 0, sizeof(curr));
        for(auto c: p)
            req[c]++;
        
        int j = -1, len = 0;
        bool po = 0;
        pair<int, int> ans;
        
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && req[s[i - 1]])
            {
                if(curr[s[i - 1] ] == req[s[i - 1] ])
                    len--;
                curr[s[i - 1]]--;
            }
            
            if(i > j && req[s[i] ])
            {
                if(curr[s[i] - 'A'] < req[s[i]])  len++;
                curr[s[i]]++;
                
                j = i;
            }
            // if(j < i)
            //     j = i;
            
            while(j < n && len < m)
            {
                j++;
                if(j == n)
                    break;
                 
                if(req[s[j] ])
                {
                    if(curr[s[j] ] < req[s[j] ])
                        len++;
                    curr[s[j] ]++;
                }            
                    
            }
            
            if(len < m)
                break;
            if(!po || (ans.second - ans.first > j - i))
                ans = {i, j};
            
            po = 1;
            
        }
        
        if(!po)
            return "";
        
        else 
            return s.substr(ans.first, ans.second - ans.first + 1);
        
    }
};