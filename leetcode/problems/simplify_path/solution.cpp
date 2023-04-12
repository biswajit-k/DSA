class Solution {
public:

    void operation(string& s, stack<string>& path) {

        if(s == "..")
        {
            if(path.size() > 1)
            {
                path.pop();
                path.pop();
            }
        }
        else if(s.length() && s != ".")
        {
            path.push(s);
            path.push("/");
        }
        s.clear();

    }

    string simplifyPath(string path) {

        int n = path.length();

        stack<string> new_path;
        new_path.push("/");
        
        string s = "";

        int i = 0;
        while(i < n)
        {
            if(path[i] != '/')
            {
                s += path[i];
                i++;
                continue;
            }

            while(i < n && path[i] == '/')   i++;

            operation(s, new_path);
        }

        operation(s, new_path);
        if(new_path.size() > 1 && new_path.top() == "/")   new_path.pop();

        string ans = "";
        while(!new_path.empty())
        {
            string res = new_path.top();
            new_path.pop();
            reverse(begin(res), end(res));

            ans += res;
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};