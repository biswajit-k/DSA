class Solution {
public:

    vector<vector<string>> ans;

    void helper(int idx, vector<string>& res, vector<vector<bool>>& is_palindrome, string& s) {

        if(idx == s.length())
        {
            ans.push_back(res);
            return;
        }
        string curr;
        for(int i = idx; i < s.length(); i++)
        {
            curr += s[i];
            if(is_palindrome[idx][i])
            {
                res.push_back(curr);
                helper(i + 1, res, is_palindrome, s);
                res.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        
        int n = s.length();
        vector<string> res;
        vector<vector<bool>> is_palindrome(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++)  is_palindrome[i][i] = true;

        for(int l = 2; l <= n; l++)
        {
            for(int i = 0; i < n; i++)
            {
                int j = i + l - 1;
                if(j >= n)  break;

                if(j == i + 1)
                    is_palindrome[i][j] = s[i] == s[j];
                else
                    is_palindrome[i][j] = (s[i] == s[j]) && is_palindrome[i + 1][j - 1];
            }
        }

        helper(0, res, is_palindrome, s);

        return ans;
    }
};