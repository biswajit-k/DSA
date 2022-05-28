class Solution {
public:
    int doit(string& s)
    {
        stringstream ss(s);
        int x = 0;
        string w;
        while(ss >> w)  x++;
        return x;
    }

    string largestWordCount(vector<string>& mess, vector<string>& send) {
       unordered_map<string, int> mp;

       int n = mess.size(), c = 0;

       for(int i = 0; i < n; i++)
       {
           mp[send[i]] += doit(mess[i]);
       }

       string ans = "";
        for(auto [name, count]: mp)
            if(count > c || (count == c && name > ans))
                c = count, ans = name;
        return ans;

    }
};
