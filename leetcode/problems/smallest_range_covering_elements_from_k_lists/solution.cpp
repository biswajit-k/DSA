class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int n = nums.size();

        set<pair<int, pair<int, int>>> st;

        for(int i = 0; i < n; i++)
            st.insert({nums[i][0], {i, 0}});

        int ans_l = 0, ans_r = 1e9;

        while(true)
        {
            auto [l, l_pr] = *st.begin();
            auto [l_row, l_idx] = l_pr;

            auto [r, r_pr] = *st.rbegin();
            auto [r_row, r_idx] = r_pr;

            if(r - l < ans_r - ans_l)
                ans_l = l, ans_r = r;

            st.erase(st.begin());
            if(l_idx == nums[l_row].size() - 1)
                break;
            
            st.insert({nums[l_row][l_idx + 1], {l_row, l_idx + 1}});
        }

        return {ans_l, ans_r};
    }
};