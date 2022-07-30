class Solution {
public:
    
    void perform(int& res, char op, int num)
    {
        if(op == '+') res += num;
        else if(op == '-') res -= num;
        else if(op == '*') res *= num;
        else if(op == '/') res /= num;
    }
    
    int calculate(string s) {

        s = '+' + s;
        
        int n = s.length(), res = 0, p_num = 0, i = 0;
        char p_op = '+';
        
        while(i < n)
        {
            char cur_op;
            int cur_num = 0;
            
            while(i < n && s[i] == ' ') i++;
            if(i == n)  break;
            
            cur_op = s[i];
            i++;
            
            while(i < n && s[i] == ' ') i++;
            while(i < n && s[i] >= '0' && s[i] <= '9')
            {
                cur_num = cur_num * 10 + (s[i] - '0');
                i++;
            }
            
            if(p_op == '*' || p_op == '/' || cur_op == '+' || cur_op == '-')
            {
                perform(res, p_op, p_num);
                p_op = cur_op;
                p_num = cur_num;
            }
            else
            {
                if(cur_op == '*')
                    p_num *= cur_num;
                else 
                    p_num /= cur_num;
            }
            
        }
        perform(res, p_op, p_num);
        
        return res;
    }
};