class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& E, vector<vector<int>>& Q) {
        
        int q = Q.size(), e = E.size();

        vector<bool> ans(q);

        vector<int> q_idx(q);
        iota(begin(q_idx), end(q_idx), 0);
        sort(begin(q_idx), end(q_idx), [&](auto& a, auto& b) {
            return Q[a][2] < Q[b][2];
        });
        sort(begin(E), end(E), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        vector<int> p(n), p_sz(n, 1);
        iota(begin(p), end(p), 0);

        /////
        function<int(int)> parent = [&](int x) {
            if(x == p[x])
                return x;
            return p[x] = parent(p[x]);
        };
        auto join = [&](int a, int b) {
            int pa = parent(a), pb = parent(b);
            if(pa == pb)
                return;
            if(p_sz[pa] > p_sz[pb])
                swap(a, b), swap(pa, pb);
            
            p_sz[pb] += p_sz[pa];
            p[pa] = pb;
        };
        ////

        int e_idx = 0;
        for(auto& i: q_idx)
        {
            int s = Q[i][0], t = Q[i][1], l = Q[i][2];
            for(;e_idx < e && E[e_idx][2] < l; e_idx++)
                join(E[e_idx][0], E[e_idx][1]);

            ans[i] = (parent(s) == parent(t) ? true : false);
        }

        return ans;
    }
};