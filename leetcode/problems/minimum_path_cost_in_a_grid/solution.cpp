
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        int n = grid.size(), m = grid[0].size();
        const int inf = 88888889;

        vector<vector<int>> cost(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++)
            cost[n - 1][i] = grid[n - 1][i];

        for(int row = n - 2; row > -1; row--)
        {
            for(int col = 0; col < m; col++)
            {
                int mi = inf;
                for(int k = 0; k < m; k++)
                    mi = min(mi, moveCost[grid[row][col]][k] + cost[row + 1][k]);

                cost[row][col] = grid[row][col] + mi;

            }
        }

        return *min_element(begin(cost[0]), end(cost[0]));

    }
};