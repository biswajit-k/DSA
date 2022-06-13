class Solution {
public:
    
    const int inf = 1e9;

    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size(), prev;
        vector<int> dis(n + 1, inf);
        
        dis[0] = triangle[0][0];
        
        for(int r = 1; r < n; r++)
        {
            prev = inf;
            for(int c = 0; c <= r; c++)
            {
                int tp = dis[c];
                dis[c] = triangle[r][c] + min(dis[c], prev);
                prev = tp;
            }
        }
        
        return *min_element(begin(dis), end(dis));
    }
};