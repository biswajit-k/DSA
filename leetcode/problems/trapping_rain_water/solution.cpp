class Solution {
public:
    int trap(vector<int>& H) {
        
        int n = H.size(), mx = 0, ans = 0;
        int idx = max_element(begin(H), end(H)) - begin(H);

        for(int i = 0; i < idx; i++)
        {
            ans += max(0, mx - H[i]);
            mx = max(mx, H[i]);
        }
        mx = 0;
        for(int i = n - 1; i > idx; i--)
        {
            ans += max(0, mx - H[i]);
            mx = max(mx, H[i]);
        }

        return ans;
    }
};