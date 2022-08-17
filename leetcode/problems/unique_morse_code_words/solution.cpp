class Solution {
public:
    
    vector<string> ary = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    string morse(string& word)
    {
        string res = "";
        for(auto c: word)
            res += ary[c - 'a'];
        
        return res;
    }
    
    int uniqueMorseRepresentations(vector<string>& words) {
        
        unordered_map<string, bool> mp;
        
        for(auto& word: words)
            mp[morse(word)] = 1;
        
        return size(mp);
        
    }
};