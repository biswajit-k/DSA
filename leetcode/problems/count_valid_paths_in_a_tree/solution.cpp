class Solution {
public:
    
    typedef long long llint;
    vector<vector<int>> adj;
    
    vector<llint> no_prime_child, no_prime_whole, one_prime_child, one_prime_whole, is_prime, par;
    
    void init(int n) {
        n += 10;
        adj.resize(n);
        no_prime_child.resize(n, -1);
        no_prime_whole.resize(n, -1);
        one_prime_child.resize(n, -1);
        one_prime_whole.resize(n, -1);
        is_prime.resize(n + 1, -1);
        par.resize(n);
    }

    void seieve() {
        int N = is_prime.size() - 1;
        for(int i = 2; i * 1LL * i <= N; i++)
            if(is_prime[i] == -1)
                for(int j = i * 1LL * i; j <= N; j += i)
                    if(is_prime[j] == -1)
                        is_prime[j] = 0;
        
        is_prime[1] = 0;
        for(int i = 2; i <= N; i++)
            if(is_prime[i] == -1)
                is_prime[i] = 1;
        
    }
    
    void set_parent(int x) {
        for(auto& c: adj[x])
            if(c != par[x])
            {
                par[c] = x;
                set_parent(c);
            }
        // cout << "hfg" << par[6];
    }
    
    void set_no_prime_child(int x) {
        if(no_prime_child[x] != -1)
            return;
        no_prime_child[x] = 0;
        if(is_prime[x])
        {
            no_prime_child[x] = 0;
            return;
        }
        
        int p = par[x];
        for(auto& c: adj[x])
            if(c != p)
            {
                set_no_prime_child(c);
                no_prime_child[x] += no_prime_child[c];
            }
        no_prime_child[x]++;
    }
    
    void set_no_prime_whole(int x) {
        if(no_prime_whole[x] != -1)
            return;
        no_prime_whole[x] = 0;
        if(is_prime[x])
        {
            no_prime_whole[x] = 0;
            return;
        }
        
        int p = par[x];
        
        if(p == -1 || is_prime[p])
        {
            set_no_prime_child(x);
            no_prime_whole[x] = no_prime_child[x];
        }
        else
        {
            set_no_prime_whole(p);
            no_prime_whole[x] = no_prime_whole[p];
        }
            
    }
    
    void set_one_prime_child(int x) {
        if(one_prime_child[x] != -1)
            return;
        one_prime_child[x] = 0;
        if(is_prime[x])
        {
            for(auto& c: adj[x])
                if(c != par[x])
                {
                    set_no_prime_child(c);
                    one_prime_child[x] += no_prime_child[c];
                }
            one_prime_child[x]++;
            return;
        }
        for(auto& c: adj[x])
            if(c != par[x])
            {
                set_one_prime_child(c);
                one_prime_child[x] += one_prime_child[c];
            }
    }
    
    void set_one_prime_whole(int x) {
        if(one_prime_whole[x] != -1)
            return;
        one_prime_whole[x] = 0;
        if(is_prime[x])
        {
            set_one_prime_child(x);
            set_no_prime_whole(par[x]);
            one_prime_whole[x] = one_prime_child[x] + no_prime_whole[par[x]];
            return;
        }
        set_one_prime_whole(par[x]);
        if(is_prime[par[x]])
        {
            set_no_prime_child(x);
            set_one_prime_child(x);
            one_prime_whole[x] = one_prime_whole[par[x]] - no_prime_child[x] + one_prime_child[x];
            return;
        }
        one_prime_whole[x] = one_prime_whole[par[x]];
    }
    
    long long countPaths(int n, vector<vector<int>>& edges) {
        
        init(n);
        seieve();
        
        for(auto& e: edges)
            adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        
        par[1] = -1;
        set_parent(1);
        // set one prime whole of root equal to child so that it is never called
        
        set_one_prime_child(1);
        one_prime_whole[1] = one_prime_child[1];
        llint ans = one_prime_whole[1];

        for(int i = 2; i <= n; i++)
        {
            set_one_prime_whole(i);
            ans += one_prime_whole[i];
            
            if(is_prime[i])
                ans--;
        }
        
        // for(int i = 1; i <= n; i++)
        //     cout << one_prime_whole[i] << ' '; 
        // cout << '\n';
        
        ans /= 2;
        return ans;
        // return 0;
    }
};