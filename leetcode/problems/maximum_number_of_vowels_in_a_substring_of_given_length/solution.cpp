class Solution {
public:

    const string vowel = "aeiou";

    bool is_vowel(char c) {
        return count(begin(vowel), end(vowel), c);
    }

    int maxVowels(string s, int k) {
        
        int n = s.size(), ans = 0, curr = 0;

        for(int i = 0; i < k; i++)
            curr += is_vowel(s[i]);

        ans = curr;
        for(int i = k; i < n; i++)
        {
            curr += is_vowel(s[i]) - is_vowel(s[i - k]);
            ans = max(ans, curr);
        }

        return ans;
    }
};