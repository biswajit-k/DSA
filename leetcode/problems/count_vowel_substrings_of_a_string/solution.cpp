class Solution {
public:
    int countVowelSubstrings(string word) {
        int count = 0;
        char vov[] = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, bool> vis;
        for(int i = 0; i < word.length(); i++)
        {   
            int all = 0;
            for(int k = 0; k < 5; k++)
                vis[vov[k]] = 0;
            for(int j = i; j < word.length(); j++)
            {
                bool isvov = 0;
                for(int k = 0; k < 5; k++)
                    if(vov[k] == word[j])
                        isvov = 1;
                if(!isvov)
                {
                    break;
                }
                if(vis[word[j]] == 0)
                    vis[word[j]] = 1, all++;
                if(all == 5)
                count++;
            }
            
        }
        return count;
    }
};