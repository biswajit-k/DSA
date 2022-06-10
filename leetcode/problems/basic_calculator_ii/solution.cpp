class Solution {
public:
    
    unordered_map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    
    bool isDigit(char x)
    {
        return (x >= '0' && x <= '9');
    }
    
    void perform(stack<char>& sign, stack<int>& num)
    {
        int o2 = num.top(); num.pop();
        int o1 = num.top(); num.pop();
        char op = sign.top(); sign.pop();
        
        if(op == '+')   num.push(o1 + o2);
        else if(op == '-')   num.push(o1 - o2);
        else if(op == '/')   num.push(o1 / o2);
        else if(op == '*')   num.push(o1 * o2);
    }
    
    int calculate(string s) {
        
        stack<int> num;
        stack<char> sign;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
                continue;
            if(isDigit(s[i]))
            {
                int x = 0;
                while(i < s.length() && isDigit(s[i]))
                {
                    x *= 10;
                    x += s[i] - '0';
                    i++;
                }
                i--;
                num.push(x);
            }
            else 
            {
                while(!sign.empty() && priority[s[i]] <= priority[sign.top()])
                    perform(sign, num);
                sign.push(s[i]);
            }
        }
        
        while(!sign.empty())
            perform(sign, num);
        
        return num.top();
        
    }
};