class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<int> block(m);
        for(int j = 0; j < m; j++)
            block[j] = matrix[0][j] - '0';

        for(int i = 0; i < n; i++)
        {
            if(i > 0)
            {
                for(int j = 0; j < m; j++)
                    block[j] = matrix[i][j] == '1' ? 1 + block[j] : 0;
            }

            stack<int> st;
            st.push(-1);   
            for(int j = 0; j < m; j++)
            {
                while(st.top() != -1 && block[st.top()] >= block[j])
                {
                    int curr = st.top();
                    st.pop();
                    int l = j - st.top() - 1;
                    ans = max(ans, min(l, block[curr]));
                }
                st.push(j);
            }
            while(st.top() != -1)
            {
                int curr = st.top();
                st.pop();
                ans = max(ans, min(block[curr], m - st.top() - 1));
            }

        }

        return ans * ans;
    }
};