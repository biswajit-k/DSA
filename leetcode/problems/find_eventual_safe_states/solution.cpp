class Solution {
public:

    void helper(int x, vector<vector<int>>& graph, vector<int>& type) {

        type[x] = 1;
        for(auto& c: graph[x])
        {
            if(!type[c])
                helper(c, graph, type);
            
            if(type[c] != 2)
                return;
        }

        type[x] = 2;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> type(n, 0);
        vector<int> ans;
        
        for(int i = 0; i < n; i++)
            if(!type[i])
                helper(i, graph, type);
        
        for(int i = 0; i < n; i++)
            if(type[i] == 2)
                ans.push_back(i);

        return ans;
    }
};