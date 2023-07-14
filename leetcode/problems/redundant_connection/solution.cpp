class Solution {
public:

    class DSU {

        vector<int> parent, group_size;

        public:

            DSU(int n) {
                parent.resize(n);
                group_size.resize(n, 1);
                iota(begin(parent), end(parent), 0);    // set the parent as the node themselves
            }

            int get_parent(int x) {
                if(x == parent[x])
                    return x;
                return parent[x] = get_parent(parent[x]);
            }

            bool join(int a, int b) {
                int parent_a = get_parent(a);
                int parent_b = get_parent(b);

                if(parent_a == parent_b)
                    return false;
                
                if(group_size[a] > group_size[b])
                    swap(a, b), swap(parent_a, parent_b);
                
                parent[parent_a] = parent_b;
                group_size[b] += group_size[parent_a];
                return true;
            }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        DSU dsu(n);

        vector<int> repeated_edge = {-1, -1};

        for(auto& edge: edges)
            if(!dsu.join(edge[0] - 1, edge[1] - 1))
                repeated_edge = edge;


        return repeated_edge;
    }
};