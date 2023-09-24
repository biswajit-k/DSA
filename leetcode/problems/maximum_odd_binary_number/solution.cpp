class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = count(begin(s), end(s), '1');
        
        string ans = "";
        for(int i = 0; i < (int)s.length() - 1; i++)
        {
            if(one > 1)
                ans += '1', one--;
            else
                ans += '0';
        }
        ans += '1';
        
        return ans;
    }
};