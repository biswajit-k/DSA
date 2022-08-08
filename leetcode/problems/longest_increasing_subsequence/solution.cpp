class Solution {
public:
    
    const static int sz = 2e4 + 3;
    int bit[sz] = {};
    
    void update(int x, int len)
    {
        for(; x <= sz; x += (x & -x))
            bit[x] = max(bit[x], len);
    }
    
    int get(int x)
    {
        int c_len = 0;
        for(; x; x -= (x & -x))
            c_len = max(c_len, bit[x]);
        return c_len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int offset = 1e4 + 1, ans = 0;
        
        for(auto& val: nums)
        {
            int x = val + offset;
            int cur_len = get(x - 1);
            update(x, cur_len + 1);
            ans = max(ans, cur_len + 1);
        }
        
        return ans;
    }
};