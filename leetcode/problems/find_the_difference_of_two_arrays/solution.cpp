class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& A, vector<int>& B) {
        
        sort(begin(A), end(A));
        sort(begin(B), end(B));

        A.resize(unique(begin(A), end(A)) - begin(A));
        B.resize(unique(begin(B), end(B)) - begin(B));

        vector<int> UA, UB;
        int i = 0, j = 0, n = A.size(), m = B.size();
        while(i < n && j < m)
        {
            if(A[i] < B[j])
                UA.push_back(A[i++]);
            else if(B[j] < A[i])
                UB.push_back(B[j++]);
            else 
                i++, j++;
        }
        while(i < n)
            UA.push_back(A[i++]);
        while(j < m)
            UB.push_back(B[j++]);

        return {UA, UB};
    }
};