class Solution {
public:
    int maxScore(vector<int>& cards, int k) {

        int n = cards.size();
        vector<int> points(n + 1);

        for(int i = 1; i <= n; i++)
            points[i] = points[i - 1] + cards[i - 1];

        int ans = points[k], curr_points = 0;

        for(int i = n - 1; i >= n - k; i--)
        {
            curr_points += cards[i];
            ans = max(ans, curr_points + points[k - n + i]);
        }

        return ans;
    }
};