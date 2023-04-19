class Solution {
public:

    int sum(int idx, vector<int>& bit) {

        int res = 0;
        for(; idx > 0; idx -= (idx & -idx))
            res += bit[idx];
        return res;
    }
    void add(int idx, int v, vector<int>& bit) {
        int n = bit.size() - 1;
        for(; idx <= n; idx += (idx & -idx))
            bit[idx] += v;
    }


    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> dup = nums;
        sort(dup.begin(), dup.end());
        dup.resize(unique(dup.begin(), dup.end()) - dup.begin());

        int m = dup.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < m; i++)
            mp[dup[i]] = i + 1;

        vector<int> bit(m + 1, 0);

        vector<int> ans(n, 0);
        for(int i = n - 1; i > -1; i--)
        {
            int x = mp[nums[i]];
            ans[i] = sum(x - 1, bit);

            add(x, 1, bit);
        }

        return ans;
    }
};