class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string res = "";

        int n = word1.size(), m = word2.size();
        int i = 0, j = 0;

        for(; i < n && j < m; i++, j++)
        {
            res += word1[i];
            res += word2[j];
        }
            
        res += word1.substr(i, n - i);
        res += word2.substr(j, m - j);

        return res;
    }
};