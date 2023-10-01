class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edge) {
        
        int n = edge.size();
        
        vector<int> ans(n, -1);
        
        function<void(int)> dfs = [&](int i) {
          
            ans[i] = 0;
            if(ans[edge[i]] == 0)
            {
                int len = 1;
                int next = edge[i];
                while(next != i)
                    next = edge[next], len++;
                ans[i] = len;
                next = edge[i];
                while(next != i)
                    ans[next] = len, next = edge[next];
                return;
            }
            if(ans[edge[i]] == -1)
                dfs(edge[i]);
            
            if(ans[i] == 0)
                ans[i] = ans[edge[i]] + 1;  
        };
        
        for(int i = 0; i < n; i++)
            if(ans[i] == -1)
                dfs(i);
        
        
        return ans;
    }
};