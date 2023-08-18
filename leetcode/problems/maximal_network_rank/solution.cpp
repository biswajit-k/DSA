class Solution {
public:

    // no. of roads of best ith node
    int get_roads(int i, vector<unordered_set<int>>& adj, vector<int>& sorted_idx) {
        return adj[sorted_idx[i]].size();
    }

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<unordered_set<int>> adj(n);

        for(auto& R: roads)
        {
            adj[R[0]].insert(R[1]);
            adj[R[1]].insert(R[0]);
        }

        // sort indices based on the number of roads connected.
        vector<int> sorted_idx(n);
        for(int i = 0; i < n; i++)
            sorted_idx[i] = i;
        
        sort(begin(sorted_idx), end(sorted_idx), [&](int i1, int i2) {
            return adj[i1].size() > adj[i2].size();
        });

        int ans = 0;
        // if 2 or more nodes have max. no. of roads
        if(get_roads(0, adj, sorted_idx) == get_roads(1, adj, sorted_idx))
        {
            ans = 2 * adj[sorted_idx[0]].size();

            // check if all nodes connected to each other
            int total_connections = 0, total_nodes = 0;
            unordered_set<int> max_connection_nodes;
            while(total_nodes < n && get_roads(0, adj, sorted_idx) == get_roads(total_nodes, adj, sorted_idx))
            {
                max_connection_nodes.insert(sorted_idx[total_nodes]);
                total_nodes++;
            }

            for(auto& node: max_connection_nodes)
            {
                for(auto& possible_node: max_connection_nodes)
                    if(possible_node != node && adj[node].find(possible_node) == adj[node].end())
                        return ans;
            }

            return ans - 1;
        }

        // otherwise take 1st node and check which one to pick from remaining
        for(int i = 1; i < n; i++)
        {
            int curr_ans = get_roads(0, adj, sorted_idx) + get_roads(i, adj, sorted_idx);
            if(adj[sorted_idx[0]].find(sorted_idx[i]) != adj[sorted_idx[0]].end())
                curr_ans--;
            ans = max(ans, curr_ans);
        }

        return ans;
    }
};

/*
each node will be taken (n - 1)times

r_i = no. of roads connected to node_i

no. of times a node is visted + no. of times a road is visited
= n * (n - 1) +  (n - 1) * (r_0 + r_1 + r_2 ... r_n-1)
= n * n + (n - 1) * n * n
= n^3

R -> total roads = n * n
each road is connected to 2 nodes

total_roads_for_node_i_and_j = r_i + r_j - (1 if edge between i and j else 0)

road_1, road_2, road_3 ...
r        r         r

2*r - 1
2*r

*/