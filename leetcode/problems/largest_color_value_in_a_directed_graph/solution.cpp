class Solution {
public:

    bool dfs(int x, vector<int> adj[], string& colors, vector<vector<int>>& dp, vector<bool>& is_active) {

        is_active[x] = 1;
        vector<int> p_length(26, 0);

        for(auto& child: adj[x])
        {
            if(is_active[child])
                return 1;

            if(dp[child].empty() && dfs(child, adj, colors, dp, is_active))
                return 1;

            for(int i = 0; i < 26; i++)
                p_length[i] = max(p_length[i], dp[child][i]);

        }

        p_length[colors[x] - 'a']++;
        dp[x] = move(p_length);

        is_active[x] = 0;
        return 0;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.size();

        vector<int> adj[n];
        for(auto& edge: edges) 
            adj[edge[0]].push_back(edge[1]);

        vector<vector<int>> dp(n);
        vector<bool> is_active(n, 0);

        int ans = 0;
        for(int i = 0; i < n; i++)
            if(dp[i].empty())
            {
                bool is_loop = dfs(i, adj, colors, dp, is_active);
                if(is_loop)
                    return -1;
                ans = max(ans, *max_element(begin(dp[i]), end(dp[i])));
            }

        return ans;
    }
};