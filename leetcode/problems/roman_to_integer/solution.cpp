class Solution {
public:
    int romanToInt(string s) {
        int val[27] = {};
        val['I' - 'A'] = 1;
        val['X' - 'A'] = 10;
        val['V' - 'A'] = 5;
        val['L' - 'A'] = 50;
        val['C' - 'A'] = 100;
        val['D' - 'A'] = 500;
        val['M' - 'A'] = 1000;
        
        int ans = 0, n = s.size();
        for(int i = 0; i < n - 1; i++)
        {
            if(val[s[i] - 'A'] >= val[s[i + 1] - 'A'])
                ans += val[s[i] - 'A'];
            else 
                ans -= val[s[i] - 'A'];
        }
        ans += val[s.back() - 'A'];
        
        return ans;
        
    }
};