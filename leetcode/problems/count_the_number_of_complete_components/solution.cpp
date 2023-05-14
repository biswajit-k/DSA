class Solution {
public:
    
    int dfs_size(int x, vector<int> adj[], vector<bool>& vis) {    
        vis[x] = 1;
        int sz = 1;
        for(auto& c: adj[x])
            if(!vis[c])
                sz += dfs_size(c, adj, vis);
        
        return sz;
    }
    
    bool dfs_check(int x, int si, vector<int> adj[], vector<bool>& vis) {
        
        vis[x] = 1;
        if((int)adj[x].size() != si)    return false;
        for(auto& c: adj[x])
            if(!vis[c] && !dfs_check(c, si, adj, vis))
                return false;
            
        return true;
    }
    
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n + 1];
        vector<bool> vis1(n + 1, 0), vis2(n + 1, 0);
        
        for(auto& e: edges) 
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
            if(!vis1[i])
            {
                int sz = dfs_size(i, adj, vis1);
                ans += dfs_check(i, sz - 1, adj, vis2);
            }
     
        return ans;
    }
};