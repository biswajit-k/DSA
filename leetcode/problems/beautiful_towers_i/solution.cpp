class Solution {
public:
    
    typedef long long llint;
    
    long long maximumSumOfHeights(vector<int>& H) {
        
        int n = H.size();
        
        llint ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            llint curr = 0;
            for(int j = i + 1, h = H[i]; j < n; j++)
            {
                h = min(h, H[j]);
                curr += h;
            }
            for(int j = i - 1, h = H[i]; j > -1; j--)
            {
                h = min(h, H[j]);
                curr += h;
            }
            
            ans = max(ans, curr + H[i]);
        }
        
        return ans;
    }
};