class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        
        int curr = 0, ans = 0;
        k = min(k, (int)cp.size());
        
        for(int i = 0; i < k; i++)
            curr += cp[i];
        
        ans = curr;
        
        int l = k - 1, r = cp.size() - 1;
        
        while(l > -1)
        {
            curr += cp[r] - cp[l];
            ans = max(ans, curr);
            l--;
            r--;
        }
        
        return ans;
     
    }
};