class Solution {
public:
     
    void dfs(int x, vector<int> adj[], bool vis[])
    {
        vis[x] = 1;     
        for(auto& node: adj[x])
            if(!vis[node])
                dfs(node, adj, vis);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n + 1];
        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));
        
        for(auto& conn: connections)
            adj[conn[0]].push_back(conn[1]), adj[conn[1]].push_back(conn[0]);
        
        int components = 0;
        
        for(int i = 0; i < n; i++)
            if(!vis[i])
            {
                components++;
                dfs(i, adj, vis);
            }
        
        int extra_edges = size(connections) - (n - components);
        if(extra_edges + 1 < components)
            return -1;
        return components - 1;
    }
};