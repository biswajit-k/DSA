class Solution {
public:

    void dfs(int x, vector<vector<int>>& matrix) {

        matrix[x][x] = 0;
        for(int i = 0; i < matrix[x].size(); i++)
            if(matrix[x][i] && matrix[i][i])
                dfs(i, matrix);
                
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int components = 0;

        for(int i = 0; i < size(isConnected); i++)
            if(isConnected[i][i])
                dfs(i, isConnected), components++;

        return components;
    }
};