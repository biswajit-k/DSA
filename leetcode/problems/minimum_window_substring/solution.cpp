class Solution {
public:
    string minWindow(string s, string p) {
        
        int curr[130], req[130], n = s.size(), m = p.size();
        for(int i = 0; i < 130; i++)
            curr[i] = req[i] = 0;
        
        for(auto c: p)
            req[c]++;
        
        int i = 0, len = 0;
        pair<int, int> ans;
        bool po = 0;
        
        for(int j = 0; j < n; j++)
        {
            curr[s[j]]++;
            if(curr[s[j]] <= req[s[j]]) len++;
            
            while(len == m)
            {
                if(!po || (ans.second - ans.first > j - i))
                    ans = {i, j};
                po = 1;
                curr[s[i]]--;
                if(req[s[i]] > curr[s[i]])
                    len--;
                i++;
            }
            
        }
        
        if(!po)
            return "";
        return s.substr(ans.first, ans.second - ans.first + 1);
            
    }
};