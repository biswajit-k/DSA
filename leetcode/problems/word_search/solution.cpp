class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size(), m = board[0].size(), len = word.size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        function<bool(int, int, int)> dfs = [&](int x, int y, int idx) {

            if(idx == len)
                return true;
            if(x < 0 || y < 0 || x >= n || y >= m)
                return false;
            if(board[x][y] != word[idx] || vis[x][y])
                return false;

            vis[x][y] = 1;

            bool possible = dfs(x + 1, y, idx + 1) || dfs(x, y + 1, idx + 1) || dfs(x - 1, y, idx + 1) || dfs(x, y - 1, idx + 1);
            vis[x][y] = 0;

            return possible;
        };

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(dfs(i, j, 0))
                    return true;

        return false;
    }
};