class Solution {
public:

    int numDecodings(string s) {
        
        int n = s.length();

        int next_ways = 1, temp = 0;
        int current_ways = (s[n - 1] == '0' ? 0 : 1);

        for(int i = n - 2; i > -1; i--)
        {
            temp = next_ways;
            next_ways = current_ways;
            current_ways = 0;
            if(s[i] != '0')
                current_ways += next_ways;
            if(i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
                current_ways += temp;
        }

        return current_ways;
    }
};