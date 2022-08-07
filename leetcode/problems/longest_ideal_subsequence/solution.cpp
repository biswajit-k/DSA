
class Solution {
public:
    int longestIdealString(string s, int k) {

        int n = s.length();
        int mx[26] = {};

        for(int i = n - 1; i > -1; i--)
        {
            int len = 0;
            for(int j = 0; j < 26; j++)
                if(abs(s[i] - 'a' - j) <= k)
                    len = max(len, mx[j]);
            mx[s[i] - 'a'] = 1 + len;
            
        }
        return *max_element(mx, mx + 26);
    }
};
