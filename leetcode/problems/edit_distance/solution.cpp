class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.length(), m = b.length();
        if(n == 0 || m == 0)
            return abs(n - m);
        vector<int> prev(m + 1), curr(m + 1);

        for(int i = 0; i <= m; i++)
            prev[m - i] = i;
        curr[m] = 1;

        for(int i = n - 1; i > -1; i--)
        {
            for(int j = m - 1; j > -1; j--)
            {
                if(a[i] == b[j])
                    curr[j] = prev[j + 1];
                else 
                {
                    int add = 1 + curr[j + 1];
                    int remove = 1 + prev[j];
                    int replace = 1 + prev[j + 1];
                    curr[j] = min({add, remove, replace});
                }
            }
            prev = curr;
            curr[m] = n - i + 1;
        }

        return curr[0];
    }
};