class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       
        int cnt[26] = {};
        
        for(auto c: ransomNote)    cnt[c - 'a']++;
        for(auto c: magazine)   cnt[c - 'a']--;
        
        for(int i = 0; i < 26; i++)
            if(cnt[i] > 0)
                return false;
        
        return true;
    }
};