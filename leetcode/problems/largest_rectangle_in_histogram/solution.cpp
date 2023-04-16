class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();

        vector<int> left(n), right(n);

        stack<int> st;

        // left -> smaller, right -> smaller or equal

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                right[st.top()] = i;
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty())
        {
            right[st.top()] = n;
            st.pop();
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));

        return ans;
    }
};