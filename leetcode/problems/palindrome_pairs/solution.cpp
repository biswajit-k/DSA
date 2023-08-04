class Solution {

    class Trie {

        public:
        Trie *child[26];
        int idx;
        vector<int> palindrome_suffix_idx;


        Trie() 
        {
            for(int i = 0; i < 26; i++)
                child[i] = nullptr;
            idx = -1;
        }

    };

    bool is_palindrome(string& w, int pos, int offset) {
        int i = 0, j = pos;

        if(offset == 1)
            i = pos, j = w.size() - 1;

        for(; i < j; i++, j--)
            if(w[i] != w[j])
                return false;

        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        Trie root;
        vector<vector<int>> ans;

        for(int i = 0; i < words.size(); i++) 
        {
            string &w = words[i];
            Trie *node = &root;

            for(int j = w.size() - 1; j > -1; j--)
            {
                if(is_palindrome(w, j, -1))
                    node -> palindrome_suffix_idx.push_back(i);

                Trie *&child_node = node -> child[w[j] - 'a'];
                if(!child_node)
                    child_node = new Trie();
                
                node = child_node;
            }
            node -> palindrome_suffix_idx.push_back(i);
            node -> idx = i;
        }

        for(int i = 0; i < words.size(); i++)
        {
            string &w = words[i];
            Trie *node = &root;

            int j = 0;
            for(; j < w.size(); j++)
            {
                if(node -> idx != -1 && node -> idx != i && is_palindrome(w, j, 1))
                    ans.push_back({i, node -> idx});
                Trie *next_node = node -> child[w[j] - 'a'];

                if(!next_node)
                    break;
                node = next_node;
            }

            if(j != w.size())
                continue;

            for(auto& idx: node -> palindrome_suffix_idx)
                if(i != idx)
                    ans.push_back({i, idx});
        }

        return ans;
    }
};