class Solution {
public:
    bool isValid(string s) {
        bool po = 1;
        
        stack<char> st;
        
        for(auto c: s)
        {
            if(c == '(' || c == '[' || c == '{')
                st.push(c);

            else if(!st.empty() && ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[')
                   || (c == '}' && st.top() == '{')))
                st.pop();
            else 
            {
                po = 0;
                break;
            }
            
        }
        if(!st.empty())
            po = 0;
        return po;                       
    }
    
};