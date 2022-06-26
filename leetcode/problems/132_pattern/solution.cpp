class Solution {
public:
    
    const int inf = 1e9 + 4;
    
    bool find132pattern(vector<int>& nums) {
        
        int mid = -inf;
        stack<int> st;
        st.push(nums.back());
        
        for(int i = nums.size() - 2; i > -1; i--)
        {
            if(nums[i] < mid)
                return true;
            while(!st.empty() && st.top() < nums[i])
            {
                mid = st.top();
                st.pop();
            }
            
            st.push(nums[i]);
        }
        
        return false;
    }
};