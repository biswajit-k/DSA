class Solution {
public: 
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        
        unordered_map<string, vector<string>> mp;
        string temp;
        
        for(int i = 0; i < strs.size(); i++)
        {
            temp = strs[i];
            sort(begin(temp), end(temp));
            mp[temp].push_back(move(strs[i]));
        }
        
        ans.resize(mp.size());
        int i = 0;
        
        for(auto& [anagram, vc]: mp)
        {
            ans[i] = (move(vc));
            i++;
        }
            
                
        return ans;
        
    }
};