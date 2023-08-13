class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        
        int n = nums.size();
        
        multiset<int> st;
        for(int i = x; i < n; i++)
            st.insert(nums[i]);
        
        int ans = 1e9 + 10;
        
        for(int i = 0; i < n && !st.empty(); i++)
        {
            auto it = st.lower_bound(nums[i]);
            
            if(it != st.end())
                ans = min(ans, abs(nums[i] - *it));
            if(it != st.begin())
            {
                it--;
                ans = min(ans, abs(nums[i] - *it));
            }
            
            st.erase(st.find(nums[i + x]));
        }
        
        return ans;
    }
};