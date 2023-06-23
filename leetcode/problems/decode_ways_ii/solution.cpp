class Solution {
public:

    const int mod = 1e9 + 7;

    int get_ways(string s) {

        if(s.length() == 1)
            return (s[0] == '*' ? 9 : 1);
        
        if(s[0] == '*' && s[1] == '*')
            return 15;  
        if(s[0] == '*')
            return (s[1] <= '6' ? 2 : 1);
        if(s[1] == '*')
        {
            if(s[0] == '1') return 9;
            if(s[0] == '2') return 6;
            return 0;
        }

        if(s[0] == '1' || (s[0] == '2' && s[1] <= '6'))
            return 1;

        return 0;
    }

    long find_ways(int pos, string& s, vector<long>& dp) {

        if(pos == s.length())
            return 1;    
        if(s[pos] == '0')
            return 0;
        if(dp[pos] != -1)
            return dp[pos];

        long ways = 0;
        // if we decode only current character
        ways = (ways + get_ways(s.substr(pos, 1)) * find_ways(pos + 1, s, dp)) % mod;

        // if we decode 2 letters for current position
        if(pos + 1 < s.length())
        ways = (ways + get_ways(s.substr(pos, 2)) * find_ways(pos + 2, s, dp)) % mod;

        return dp[pos] = ways;
    }

    int numDecodings(string s) {
        
        vector<long> dp(s.length() + 1, -1);
        return find_ways(0, s, dp);
    }
};


/*
0
**,9215

find_ways(pos)  -> number of ways to decode string from [pos, end]

find_way(0) = 9 * find_ways(1)

function get_ways(s):   // returns no. of ways to decode this string


* -> [1, 9] = 9
x -> 1
** -> [11, 19], [21, 26] = 9 + 6 = 15
x* -> x = 0, then 0 ... x = 1, then 9 ... x = 2, then 6
*x -> x<=6, then 2 ... else 1
xx -> usual way

*/