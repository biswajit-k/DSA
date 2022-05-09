class Solution {
public:
    
    unordered_map<char, vector<char>> mp = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
        
    };

    vector<string> letterCombinations(string digits) {
        queue<string> res;
        
        for(char dig: digits)
        {
            int sz = res.size();
            if(!sz)
            {
                for(char c: mp[dig])
                {
                    string r = "";
                    r += c;
                    res.push(r);
                }
                    
            }
            else 
                for(int i = 0; i < sz; i++)
                {
                    string cur = res.front();
                    res.pop();
                    for(auto c: mp[dig])
                        res.push(cur + c);
                }
        }
        vector<string> ans(res.size());
        int p = 0;
        while(!res.empty())
        {
            ans[p] = res.front();
            res.pop();
            p++;
        }
        return ans;
        
    }
    
};