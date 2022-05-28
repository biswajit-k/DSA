
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> ans(n, 0);
        for(auto v: roads)
            ans[v[0]]++, ans[v[1]]++;
        sort(begin(ans), end(ans), greater<int>());

        long long res = 0, c = n;
        for(auto v: ans)
        {
            res += c * v;
            c--;
        }
        return res;

    }
};
