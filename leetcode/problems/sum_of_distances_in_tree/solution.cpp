class Solution {
public:

    int get_child_sum(int x, int p, vector<int> adj[], vector<int>& child_count) {

        int sum = 0, children = 0;
        for(auto& c: adj[x])
            if(c != p)
            {
                sum += get_child_sum(c, x, adj, child_count);
                sum += child_count[c] + 1;
                children += child_count[c] + 1;
            }

        child_count[x] = children;
        return sum;
    }

    void set_all_sum(int x, int p, int n, vector<int> adj[], vector<int>& child_count, vector<int>& ans) {

        if(p != -1)
            ans[x] = ans[p] - 2 * child_count[x] - 2 + n;
        
        for(auto& c: adj[x])
            if(c != p)
                set_all_sum(c, x, n, adj, child_count, ans);

    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];
        for(auto& edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> child_count(n, 0), ans(n, 0);

        ans[0] = get_child_sum(0, -1, adj, child_count);

        set_all_sum(0, -1, n, adj, child_count, ans);

        return ans;
    }
};