
/*

    TrieNode:
        unordered_map<char, TrieNode*> children;
        int ending_words = 0;

    functions:
    1. add_word(word, root) -> void     // adds word to the Trie
    2. search_character(c, root) -> int     // shift root to char 'c'  if exsit and return no. of matching words which end at c
    3. delete_node(node) -> void    // if no child 

*/

class Solution {
public:

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    struct Trie {
        unordered_map<char, Trie*> children;
        int ending_words = 0;
    };

    void add_word(string& word, Trie* root) {
        for(auto c: word) 
        {
            if(root->children.count(c) == 0)
                root->children[c] = new Trie();
            root = root->children[c];
        }
        root->ending_words++;
    }

    bool helper(int i, int j, string s, Trie *root, vector<string>& res, vector<vector<char>>& board) {

        char curr = board[i][j];
        s += curr;
        board[i][j] = ' ';

        if(root->ending_words)
            res.push_back(s);
        root->ending_words = 0;

        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if((min(x, y) < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == ' '))
                continue;
            if(root->children.count(board[x][y]))
            {
                auto is_empty = helper(x, y, s, root->children[board[x][y]], res, board);
                if(is_empty)
                    root->children.erase(board[x][y]);
            }
        }
        board[i][j] = curr;
        bool all_empty = root->children.empty();

        // if(all_empty)
        //     delete root;

        return all_empty;
    }

    void clear_trie(Trie *root) {}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Trie *root = new Trie();
        for(auto& w: words)
            add_word(w, root);

        vector<string> res;
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(root->children.count(board[i][j]))
                {
                    auto is_empty = helper(i, j, "", root->children[board[i][j]], res, board);
                    if(is_empty)
                        root->children.erase(board[i][j]);
                    if(root->children.empty())
                        return res;
                }

        return res;
    }
};