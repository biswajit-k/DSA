class Solution {
public:
    long long countVowels(string word) {
        long long count = 0;
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < word.length(); i++)
        {
            bool present = 0;
            for(auto x: v)
                if(x == word[i])
                    present = 1;
            if(present)
                count += (i + 1) * (word.length() - i);
        }
        return count;
    }
};