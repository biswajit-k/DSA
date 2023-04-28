class Solution {
public:

    bool similar(string& a, string& b) {
        int diff = 0;
        for(int i = 0; i < a.size(); i++)
            if(a[i] != b[i] && ++diff > 2)
                return false;
        return true;
    }   

    int numSimilarGroups(vector<string>& strs) {

        int n = strs.size();

        vector<int> p(n), p_size(n, 1);
        iota(begin(p), end(p), 0);

        //////////
        function<int(int)> get_parent = [&](int x) {
            if(p[x] == x)
                return x;
            return p[x] = get_parent(p[x]);
        };

        auto join = [&](int a, int b) {
            int pa = get_parent(a), pb = get_parent(b);

            if(p_size[pa] > p_size[pb])
                swap(a, b), swap(pa, pb);

            p_size[b] += p_size[a];
            p[pa] = pb;
        };

        /////////
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(similar(strs[i], strs[j]))
                    join(i, j);

        int ans = 0; 
        for(int i = 0; i < n; i++)
            if(p[i] == i)
                ans++;
        
        return ans;
    }
};