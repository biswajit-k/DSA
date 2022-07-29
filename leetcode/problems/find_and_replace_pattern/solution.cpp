class Solution {
public:
    
    string F(string s){
        unordered_map<char, char> mapped;
        char unused = 'a';
        string res = "";
        
        for(auto c: s)
            if(mapped.find(c) != mapped.end())  res += mapped[c];
            else
            {
                mapped[c] = unused;
                res += mapped[c];
                unused++;
            }
        
        return res;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        
        for(auto& word: words)
            if(F(word) == F(pattern))   ans.push_back(word);
        
        return ans;
    }
};