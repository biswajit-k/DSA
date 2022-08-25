class Solution {
public:
    
    int get_space(string& s) {
        return int(s.find(' '));
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<string> res;
        
        for(auto& log: logs)
        {
            int space = get_space(log);
            if(log[space + 1] >= 'a' && log[space + 1] <= 'z')
                res.push_back(log);
        }
        
        auto cmp = [&](string& s1, string& s2) {
            int space1 = get_space(s1);
            int space2 = get_space(s2);
            
            string subs1 = s1.substr(space1);
            string subs2 = s2.substr(space2);
            
            if(subs1 != subs2) return subs1 < subs2;
            else return (s1.substr(0, space1) < s2.substr(0, space2));            
        };
        
        sort(begin(res), end(res), cmp);
        
        for(auto& log: logs)
        {
            int space = get_space(log);
            if(log[space + 1] >= '0' && log[space + 1] <= '9')
                res.push_back(log);
        }
        
        return res;
    }
};