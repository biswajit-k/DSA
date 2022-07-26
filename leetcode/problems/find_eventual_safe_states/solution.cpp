class Solution {
public:
    
    int dfs(int x, vector<vector<int>>& graph, int status[])
    {
        if(status[x])
            return status[x];
        
        status[x] = 1;
        
        for(int i = 0; i < graph[x].size(); i++)
            if(dfs(graph[x][i], graph, status) == 1)
                return 1;
        
        return status[x] = 2;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        int status[n + 1];
        
        memset(status, 0, sizeof(status));
        
        for(int i = 0; i < n; i++)
            if(!status[i])
                status[i] = dfs(i, graph, status);
        
        vector<int> ans;
        for(int i = 0; i < n; i++)
            if(status[i] == 2)
                ans.push_back(i);
        
        return ans;
    }
};