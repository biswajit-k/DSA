class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        
        unordered_set<int> st;
        
        int p = 0;
        for(int i = 1; i <= n && !st.count(p); p = (p + i * k) % n, i++)
            st.insert(p);

        vector<int> ans;
        for(int i = 0; i < n; i++)
            if(!st.count(i))
                ans.push_back(i + 1);
        
        return ans;
    }
};