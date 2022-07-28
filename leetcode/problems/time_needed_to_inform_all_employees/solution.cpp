class Solution {
public:
    
    int dfs(int x, vector<int> adj[], vector<int>& time)
    {
        int total_time = 0;
        
        for(auto& node:adj[x])
        {
            int t = dfs(node, adj, time);
            total_time = max(total_time, t);
        }
        return total_time + time[x];
    }
        
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> adj[n + 1];
        for(int i = 0; i < n; i++)
            if(manager[i] != -1)
                adj[manager[i]].push_back(i);
        
        return dfs(headID, adj, informTime);
        
    }
};