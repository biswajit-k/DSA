class Solution {
public:
    
    vector<vector<int>> ans;
    
    int dfs(int node, int par, vector<int> adj[], vector<int>& pos, vector<int>& parent)
    {
        if(pos[node] != -1)
            return parent[node];
        
        
        pos[node] = (par == -1 ? 0 : pos[par] + 1);
        parent[node] = pos[node];
        
        for(auto x: adj[node])
            if(x != par)
            {
                parent[node] = min(parent[node], dfs(x, node, adj, pos, parent));

            }
        
        if(par != -1 && parent[node] > pos[par])
        {
            vector<int> res = {node, par};
            ans.push_back(res);
        } 
        
        if(par != -1)
        parent[node] = min(parent[node], pos[par]);
        
        return parent[node];
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> pos(n, -1), parent(n, -1);
        
        vector<int> adj[n + 1];
        for(vector<int>& vc: connections)
        {
            int u = vc[0], v = vc[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(0, -1, adj, pos, parent);
        
        return ans;
    }
};