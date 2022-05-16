class Solution {
public:
    string reorganizeString(string s) {
        
        int freq[26], n = s.length();
        for(int i = 0; i < 26; i++) freq[i] = 0;
        for(auto c: s)
                freq[c - 'a']++;
        
        for(int i = 0; i < n ; i++)
        {
            int pos = -1;
            for(int j = 0; j < 26; j++)
                if((i == 0 || (s[i - 1] - 'a' != j)) && (pos == -1 || freq[j] > freq[pos]) && freq[j])
                    pos = j;
            if(pos == -1)
                return "";
            s[i] = (pos + 'a');
            freq[pos]--;
        }
        return s;
        
    }
};