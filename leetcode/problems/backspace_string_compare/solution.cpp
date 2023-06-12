class Solution {


    void process(int& i, int& cnt, string& s) {
        
        while(i > -1 && (cnt || s[i] == '#'))
        {
            if(s[i] == '#')
                cnt++;
            else 
                cnt--;
            i--;
        }
    }

public:
    bool backspaceCompare(string s, string t) {
        
        int i = s.length() - 1, j = t.length() - 1;
        int cnt1 = 0, cnt2 = 0;

        while(i > -1 && j > -1)
        {
            process(i, cnt1, s);
            process(j, cnt2, t);
            
            if(i == -1 || j == -1 || s[i] != t[j])  break;
            i--, j--;
        }
        process(i, cnt1, s);
        process(j, cnt2, t);

        return (i == -1 && j == -1);
    }
};