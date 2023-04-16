class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {

    vector<int> adj[n];
    for(auto& edge: edges)
        adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);

    vector<int> times(n);

    function<bool(int, int, vector<bool>&)> go = [&](int x, int final, vector<bool>& vis) {

        if(x == final)
        {
            times[x]++;
            return 1;
        }

        vis[x] = 1;

        for(auto& child: adj[x])
        {
            if(!vis[child])
            {
                bool exist = go(child, final, vis);
                if(exist)
                {
                    times[x]++;
                    return 1;
                }
            }
        }

        return 0;
    };

    vector<bool> vis(n);
    for(auto& trip: trips)
    {
        go(trip[0], trip[1], vis);
        for(int i = 0; i < n; i++)
            vis[i] = 0;
    }

    vector<int> dp1(n), dp2(n);

    function<void(int, int)> dfs = [&](int x, int p) {

        int c1 = 0, c2 = 0;

        for(auto& child: adj[x])
            if(child != p)
            {
                if(!dp1[child]) dfs(child, x);

                c2 += dp1[child];
                c1 += min(dp1[child], dp2[child]);
            }

        dp1[x] = times[x] * price[x] + c1;
        dp2[x] = price[x] / 2 * times[x] + c2;
    };

    dfs(0, -1);

    return min(dp1[0], dp2[0]);
}

};