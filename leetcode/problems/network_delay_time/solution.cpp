class Solution {
public:
    
    void dfs(int node, vector<pair<int, int>> adj[], int dis[])
    {
        for(auto [x, wi]: adj[node])
        {
            if(dis[x] > dis[node] + wi)
            {
                dis[x] = dis[node] + wi;
                dfs(x, adj, dis);
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 4];
        int dis[n + 4];
        const int inf = 10000000;
        for(int i = 0; i < n + 3; i++)
                dis[i] = inf;
        
        for(auto arr: times)
        {
            int u = arr[0], v = arr[1], w = arr[2];
            adj[u].push_back({v, w});
        }
        dis[k] = 0;
        dfs(k, adj, dis);
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = max(ans, dis[i]);
        
        // return dis[3];
        return (ans == inf ? -1 : ans);
        
    }
};