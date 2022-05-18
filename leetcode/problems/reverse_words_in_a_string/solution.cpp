class Solution {
public:
    string reverseWords(string s) {
        
        string ans = "", cur;
        stringstream ss(s);
        
        while(ss >> cur)
        {
            reverse(cur.begin(), cur.end());
            ans += cur;
            ans += " ";
        }
        ans.pop_back();
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};