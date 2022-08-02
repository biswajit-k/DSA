class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        
        int n = m.size(), l = -1e9, r = 1e9;
        
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            
            int cnt = 0;
            for(int i = 0; i < n;i++)
                cnt += upper_bound(begin(m[i]), end(m[i]), mid) - begin(m[i]);
            
            if(cnt < k)
                l = mid + 1;
            else 
                r = mid;
        }
        
        return l;
    }
};