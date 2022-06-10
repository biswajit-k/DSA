class Solution {
public:
    
    
    int calculate(string s) {
        
        stringstream ss('+' + s);
        
        int res = 0, last = 0, curr;
        char op;
        
        while(ss >> op >> curr)
        {
            if(op == '+' || op == '-')
            {
                res += last;
                last = (op == '+' ? curr : -curr);
            }
            else 
            {
                if(op == '*')
                    last *= curr;
                else 
                    last /= curr;
            }
        }
        
        res += last;
        return res;
        
    }
};