class Solution {
public:
    bool isValidSerialization(string preorder) {

        preorder += ',';
        stack<string> st;
        string curr = "";

        for(auto c: preorder)
        {
            if(c == ',')
            {
                if(curr == "#")
                {
                    while(!st.empty() && st.top() == "#")
                    {
                        if(st.size() < 2)   
                            return false;
                        st.pop();
                        st.pop();
                    }
                    st.push("#");
                }
                else 
                    st.push(curr);
                
                curr = "";
            }
            else curr += c;
        }

        return st.size() == 1 && st.top() == "#";
    }
};