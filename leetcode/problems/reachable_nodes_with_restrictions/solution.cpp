class Solution {
public:

    int dfs(int x, vector<int>adj[], bool vis[])
    {
        vis[x] = 1;
        int cnt = 0;
        for(auto& node: adj[x])
            if(!vis[node])
                cnt += dfs(node, adj, vis);
        return 1 + cnt;
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {

        vector<int> adj[n + 1];
        for(auto& edge: edges)
        {
            int x = edge[0], y = edge[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }        
        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));
        for(auto& x: restricted)    vis[x] = 1;
        return dfs(0, adj, vis);

    }
};