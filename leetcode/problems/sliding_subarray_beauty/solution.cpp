class Solution {
public:
    
    /*
            fenwick tree depend on number range
                [-1e6, 1e6] => add offset => new range [0, 2e6]
                    time -> O(logN)
                any range but numbers known => map
        
    */
    
    void add(int idx, int v, vector<int>& bit) {
        
        for(; idx < bit.size(); idx += (idx & -idx))
            bit[idx] += v;
    }
    
    int sum(int idx, vector<int>& bit) {
        
        int ans = 0;
        for(; idx > 0; idx -= (idx & -idx))
            ans += bit[idx];
        return ans;
    }
    
    int search(int pos, vector<int>& bit, vector<int>& dup) {
        
        int l = 1, r = bit.size() - 1;
        
        while(l < r) 
        {
            int m = (l + r) / 2;
            
            int s = sum(m, bit);
            
            if(s < pos)
                l = m + 1;
            else 
                r = m;
        }
        return min(0, dup[l - 1]);
    }
    
    
    vector<int> getSubarrayBeauty(vector<int>& A, int k, int x) {
        
        int n = A.size();
        
        
        vector<int> dup = A;
        sort(begin(dup), end(dup));
        dup.resize(unique(begin(dup), end(dup)) - begin(dup));
        
        int m = dup.size();
        
        vector<int> bit(m + 1, 0), res;
        unordered_map<int, int> mp;
        for(int i = 0; i < m; i++)
            mp[dup[i]] = i + 1;
        
        for(int i = 0; i < k; i++)
            add(mp[A[i]], 1, bit);
        
        res.push_back(search(x, bit, dup));
        
        for(int i = k; i < n; i++)
        {
            add(mp[A[i - k]], -1, bit);
            add(mp[A[i]], 1, bit);
            
            res.push_back(search(x, bit, dup));
        }
        
        return res;
    }
};