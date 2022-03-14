class Solution {
public:
    string simplifyPath(string path) {
        stack<string> ans;
        ans.push("/");
        string curr = "";
        
        for(auto c: path)
        {
            if(c == '/')
            {
                string now = curr;
                curr = "";
                if(now == "..")
                {
                    if(ans.size() > 2)
                    {
                        ans.pop();
                        ans.pop();
                    }
                        
                }
                else if(now == "." || now == "")
                    continue;
                else 
                    ans.push(now), ans.push("/");    
                    
            }
            else 
                curr.push_back(c);
        }
        
        stack<string> s2;
        string now = curr;
        curr = "";
        if(now == "..")
        {
            if(ans.size() > 2)
            {
                ans.pop();
                ans.pop();
            }

        }
        else if(now == "." || now == "")
            curr = "4";
        else 
            ans.push(now); 
        
        if(ans.top() == "/")
            ans.pop();
        while(!ans.empty())
        {
            s2.push(ans.top());
            ans.pop();
        }
        string res = "";
        while(!s2.empty())
            res += s2.top(), s2.pop();
        
        if(res.length() == 0)
            res = "/";
        return res;
    }
};