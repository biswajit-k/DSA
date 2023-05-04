class Solution {
public:
    string predictPartyVictory(string S) {
        
        int n = S.size();
        int r = count(S.begin(), S.end(), 'R');
        int d = count(S.begin(), S.end(), 'D');
        int r_skip = 0, d_skip = 0;

        while(r && d)
        {
            for(int i = 0; i < n && r && d; i++)
            {
                if(S[i] == 'x') continue;
                if(S[i] == 'R')
                {
                    if(r_skip)
                    {
                        S[i] = 'x';
                        r_skip--;
                        continue;
                    }
                    d_skip++;
                    if(--d == 0)    break;
                }
                else 
                {
                    if(d_skip)
                    {
                        S[i] = 'x';
                        d_skip--;
                        continue;
                    }
                    r_skip++;
                    if(--r == 0)    break;
                }
            }

        }

        return (r ? "Radiant" : "Dire");
    }
};