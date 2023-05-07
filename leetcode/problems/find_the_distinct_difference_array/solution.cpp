class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& A) {
        
        int n = A.size();
        
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++)
            ans[i] = (int)(set<int>(A.begin(), A.begin() + i + 1)).size() - (int)(set<int>(A.begin() + i + 1, A.end())).size();

        return ans;
    }
};