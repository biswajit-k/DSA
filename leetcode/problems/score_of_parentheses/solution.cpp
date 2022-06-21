class Solution {
public:
    int scoreOfParentheses(string ss) {
        
        stack<int> s;
        s.push(0);
        
        for(int i = 0; i < ss.length(); i++)
        {
            if(ss[i] == '(')
            {
                s.push(0);
                continue;
            }
                
            int top = s.top();
            s.pop();
            int curr = s.top();
            s.pop();
            if(top == 0)
                curr += 1;
            else 
                curr += top * 2;
            s.push(curr);
                
        }
        return s.top();
    }
};