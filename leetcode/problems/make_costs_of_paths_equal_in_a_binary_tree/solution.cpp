class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        
        int l = log2(n), pw = (n + 1) / 2, ans = 0;
        
        while(l)
        {
            for(int i = pw - 1, j = 0; j < pw / 2; j++, i--)
            {
                ans += abs(cost[2 * i - 1] - cost[2 * i]);
                cost[i - 1] += max(cost[2 * i - 1], cost[2 * i]);
            }
            
            pw /= 2;
            l--;
        }
        
        return ans;
    }
};