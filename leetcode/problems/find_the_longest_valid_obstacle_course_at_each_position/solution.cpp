class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& H) {
        
        int n = H.size();

        set<int> heights;
        unordered_map<int, int> h_ans;
        vector<int> ans(n);

        for(int i = 0; i < n; i++)
        {
            auto it = heights.upper_bound(H[i]);
            if(it == heights.begin())
            {
                heights.insert(H[i]);
                h_ans[H[i]] = 1;
            }
            else 
            {
                it--;
                int new_ans = h_ans[*it] + 1;
                it = heights.lower_bound(H[i]);

                while(it != heights.end() && h_ans[*it] <= new_ans)
                    h_ans.erase(*it),it = heights.erase(it);

                heights.insert(H[i]);
                h_ans[H[i]] = new_ans;
            }

            ans[i] = h_ans[H[i]];
        }

        return ans;
    }
};