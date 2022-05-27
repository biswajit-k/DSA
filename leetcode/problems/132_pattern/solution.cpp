class Solution {
public:
    
    const int inf = 1e9 + 1;
    
    bool find132pattern(vector<int>& nums) {
        
        int k = -inf;
        stack<int> st;
        for(int i = size(nums) - 1; i > -1; i--)
        {
            if(nums[i] < k)
                return true;
            while(!st.empty() && st.top() < nums[i])
            {
                k = st.top();
                st.pop();
            }
            st.push(nums[i]);
            
        }
        
        return false;
    }

};

/*
    nums 4 6 5 1 ... .... 5 7 3 2
    ary  0 3

*/