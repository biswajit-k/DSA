class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m = n;
        vector<vector<int>> A(n, vector<int>(n));

        vector<pair<int, int>> order = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<pair<int, int>> change = {{1, 0}, {0, 1}, {1, 0}, {0, 1}};

        int x = 0, y = -1, chance = 0, no = 1;

        while(n && m) 
        {
            int times = !order[chance].first ? m : n;
            auto [dx, dy] = order[chance];

            for(int i = 0; i < times; i++)
            {
                x += dx;    y += dy;
                A[x][y] = no++;
            }            
            n -= change[chance].first;
            m -= change[chance].second;

            chance = (chance + 1) % 4;
        }
        return A;
    }
};