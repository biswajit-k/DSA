class Solution {
public:
    
    int ans = 0;
    
    struct Trie {
        bool isLeaf;
        Trie* child[26];
    };
    
    Trie* getNode()
    {
        Trie* node = new Trie();
        node -> isLeaf = false;
        for(int i = 0; i < 26; i++)
            node -> child[i] = nullptr;
        return node;
    }
    
    // return true if matching prefix word present    
    bool insert(Trie* root, string& w)
    {
        // if no new node is added then it is prefix of some other word
        bool nodeAdded = false;
        Trie* curr = root;
        
        for(auto c: w)
        {
            int idx = c - 'a';
            if(!(curr -> child[idx]))
            {
                curr -> child[idx] = getNode();
                nodeAdded = true;
            }
            curr = curr -> child[idx];
        }
        
        curr -> isLeaf = true;
        return !nodeAdded;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
      
        int cnt = 0;
        Trie* root = getNode();
        
        auto cmp = [](string& w1, string& w2){
          return w1.length() > w2.length();  
        };
        sort(begin(words), end(words), cmp);
        
        for(auto& w: words)
        {
            reverse(begin(w), end(w));
            if(!insert(root, w))
                cnt++, ans += w.size();
        }
        
        return ans + cnt;
    }
    
};