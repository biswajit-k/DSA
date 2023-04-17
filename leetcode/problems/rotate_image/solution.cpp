class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        
        int n = mat.size();

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int i = 0, s = n; s > 0 ; i++, s -= 2)
        {
            int r1 = i, c1 = i;
            int r2 = r1 + s - 1, c2 = c1 + s - 1;

            for(int off = 0; off < s - 1; off++)
            {
                int r = r1, c = c1;
                vector<int> values;
                for(auto& [x, y]: dir)
                {
                    values.push_back(mat[r + off * x][c + off * y]);
                    r += x * (s - 1);
                    c += y * (s - 1);
                }
                reverse(begin(values), end(values));
                reverse(begin(values) + 1, end(values));
                r = r1, c = c1;
                int j = 0;
                for(auto& [x, y]: dir)
                {
                    mat[r + off * x][c + off * y] = values[j++];
                    r += x * (s - 1);
                    c += y * (s - 1);
                }

            }

        }

    }
};