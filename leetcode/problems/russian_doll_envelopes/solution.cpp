class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& a) {
        
        vector<int> ans;
        int n = a.size(), pos = 0;
        
        sort(begin(a), end(a), [](vector<int>& p, vector<int>& q){
            if(p[0] < q[0] || (p[0] == q[0] && p[1] > q[1]))
                return 1;
            return 0;
        });
        
        while(pos < n)
        {
            int x = a[pos][0], y = a[pos][1];   

            auto it = lower_bound(begin(ans), end(ans), y);
            if(it == ans.end())
                ans.push_back(y);
            else 
                *it = y;
            pos++;
        }
        
        return int(ans.size());
        
    }
};