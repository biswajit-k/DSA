class Solution {
public:
    double average(vector<int>& A) {
        
        int avg = accumulate(A.begin(), A.end(), 0) - *min_element(begin(A), end(A)) - *max_element(begin(A), end(A));
        
        return double(avg)/(int(A.size()) - 2);

    }
};