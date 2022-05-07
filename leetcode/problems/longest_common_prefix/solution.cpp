class Solution {
public:
    
    bool match(int i, vector<string>& strs)
    {
        for(int j = 1; j < strs.size(); j++)
            if(strs[0][i] != strs[j][i])
                return 0;
        return 1;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i < strs[0].size(); i++)
            if(match(i, strs))
                ans += strs[0][i];
            else 
                break;
        
        return ans;
    }
};