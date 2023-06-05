class Solution {
public:
    string decodeString(string s) {
        
        stack<string> curr_str;
        stack<int> repeat;
        int curr = 0;
        curr_str.push("");

        for(auto c: s)
        {
            if(c >= '0' && c <= '9')
            {
                curr *= 10;
                curr += c - '0';
            }
            else if(c == '[')
            {
                repeat.push(curr);
                curr = 0;
                curr_str.push("");
            }
            else if(c >= 'a' && c <= 'z')
                curr_str.top() += c;
            else 
            {
                int k = repeat.top();
                repeat.pop();
                string now = move(curr_str.top());
                curr_str.pop();

                for(int i = 0; i < k; i++)
                    curr_str.top() += now;
            }

        }

        return curr_str.top();
    }
};