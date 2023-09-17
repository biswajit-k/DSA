class Solution {
public:
    int minAddToMakeValid(string s) {
        int adds = 0, open = 0;

        for(auto c: s)
        {
            if(c == '(')
                open++;
            else if(open)
                open--;
            else
                adds++;
        }

        adds += open;
        return adds;
    }
};