class Solution {
public:
    
    bool is_superset(string& word, int req_freq[])
    {
        int curr_freq[26] = {0};
        for(auto c: word)   curr_freq[c - 'a']++;
        for(int i = 0; i < 26; i++)
            if(req_freq[i] > curr_freq[i])  return false;
        
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        int req_freq[26] = {0};
        
        for(auto& word: words2)
        {
            int curr_freq[26] = {0};
            for(auto c: word)   curr_freq[c - 'a']++;
            for(int i = 0; i < 26; i++) req_freq[i] = max(req_freq[i], curr_freq[i]);
        }
        
        vector<string> ans;
        
        for(auto& word: words1)
            if(is_superset(word, req_freq)) ans.push_back(word);
            
        return ans;
        
    }
};