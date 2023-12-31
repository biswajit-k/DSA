
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        
        double ans = 0;
        int prev = 0;

        for(int i = 0; i < brackets.size() && (income - prev > 0); i++)
        {
            ans += ((min(income, brackets[i][0]) - prev) * (double)brackets[i][1]) / double(100);
            prev = brackets[i][0];
        }
        
        return ans;

    }
};
