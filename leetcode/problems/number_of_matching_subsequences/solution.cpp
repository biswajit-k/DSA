class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n = s.length();
        int next[n][26];
        
        for(int i = 0; i < 26; i++)
            next[n - 1][i] = n;
        
        next[n - 1][s[n - 1] - 'a'] = n - 1;
        
        for(int i = n - 2; i > -1; i--)
        {
            for(int j = 0; j < 26; j++) next[i][j] = next[i + 1][j];
            next[i][s[i] - 'a'] = i;
        }
        
        int ans = 0;
        
        for(auto& word: words)
        {
            int i = 0, pos = 0;
            for(; i < word.length() && pos < n; i++)
            {
                pos = next[pos][word[i] - 'a'] + 1;
                if(pos > n)
                    break;
            }
            if(i == word.length())
                ans++;
        }
        
        return ans;
    }
};