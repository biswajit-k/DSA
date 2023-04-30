class DSU {
        vector<int> Parent, Rank;
        public:
        DSU(int n) {
            Parent.resize(n);
            Rank.resize(n, 0);
            for (int i = 0; i < n; i++) Parent[i] = i;
        }
        int find(int x) {
            return Parent[x] = Parent[x] == x ? x : find(Parent[x]);
        }
        bool join(int x, int y) {
            int xset = find(x), yset = find(y);
            if (xset != yset) {
                Rank[xset] < Rank[yset] ? Parent[xset] = yset : Parent[yset] = xset;
                Rank[xset] += Rank[xset] == Rank[yset];
                return true;
            }
            return false;
        }
    };
class Solution {

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        sort(edges.begin(), edges.end(), greater());
        vector<DSU> group(2, n + 1);

        int res = 0, g1 = n, g2 = n;
        for(auto& edge: edges)
        {
            int t = edge[0], u = edge[1], v = edge[2];

            if(t == 3)
            {
                res += group[0].join(u, v);
                if(group[1].join(u, v))
                    g1--, g2--;
            }
            else if(t == 2)
            {
                if(group[1].join(u, v))
                    res++, g2--;
            }
            else if(t == 1)
            {
                if(group[0].join(u, v))
                    res++, g1--;
            }
            if(g1 == 1 && g2 == 1)
                return (int)edges.size() - res;
        }
        return -1;
    }
};