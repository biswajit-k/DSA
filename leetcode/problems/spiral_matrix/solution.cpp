class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        
        int n = A.size(), m = A[0].size();
        vector<int> ans;

        vector<pair<int, int>> order = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<pair<int, int>> change = {{1, 0}, {0, 1}, {1, 0}, {0, 1}};

        int x = 0, y = -1, chance = 0;

        while(n && m) 
        {
            int times = !order[chance].first ? m : n;
            auto [dx, dy] = order[chance];

            for(int i = 0; i < times; i++)
            {
                x += dx;    y += dy;
                ans.push_back(A[x][y]);
            }            
            n -= change[chance].first;
            m -= change[chance].second;

            chance = (chance + 1) % 4;
        }
        return ans;
    }
};