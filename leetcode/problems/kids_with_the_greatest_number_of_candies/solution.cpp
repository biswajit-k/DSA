class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        
        int n = candies.size();
        int mx = *max_element(begin(candies), end(candies));

        vector<bool> result(n);
        for(int i = 0; i < n; i++)
            result[i] = (candies[i] + extra >= mx);
        
        return result;
    }
};