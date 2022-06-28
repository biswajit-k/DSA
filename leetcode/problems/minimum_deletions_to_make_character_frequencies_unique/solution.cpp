class Solution {
public:
    int minDeletions(string s) {
        
        int freq[26];
        memset(freq, 0, sizeof(freq));
        
        int removal = 0;
        
        for(auto c: s)
            freq[c - 'a']++;
        
        sort(freq, freq + 26, greater<int>());
        
        for(int i = 1; i < 26; i++)
            if(freq[i] && freq[i] >= freq[i - 1])
            {
                int new_i = max(freq[i - 1] - 1, 0);
                
                removal += freq[i] - new_i;
                freq[i] = new_i;
            }
        
        return removal;
    }
};