class Solution {
public:

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    void helper(int x, int y, int old_color, int new_color, vector<vector<int>>& image) {

        if(x >= image.size() || y >= image[0].size() || x < 0 || y < 0 || image[x][y] != old_color)
            return;
        
        image[x][y] = new_color;
        for(int i = 0; i < 4; i++)
            helper(x + dx[i], y + dy[i], old_color, new_color, image);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    
        if(color != image[sr][sc])
            helper(sr, sc, image[sr][sc], color, image);
        return image;
    }
};