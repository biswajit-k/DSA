class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& Q) {
        
        int q = Q.size();
        vector<int> ans(q, 0);
        
        int groups = 0;
        vector<int> C(n, 0);
        
        for(int i = 0; i < q; i++)
        {
            int idx = Q[i][0], c = Q[i][1];
            
            int prev = ((idx == n - 1 || !C[idx]) ? 0 : C[idx] == C[idx + 1]) + ((idx == 0 || !C[idx]) ? 0 : C[idx] == C[idx - 1]);
            C[idx] = c;
            int curr = ((idx == n - 1 || !C[idx]) ? 0 : C[idx] == C[idx + 1]) + ((idx == 0 || !C[idx]) ? 0 : C[idx] == C[idx - 1]);
            
            groups += curr - prev;
            ans[i] = groups;
        }
        
        return ans;
    }
};