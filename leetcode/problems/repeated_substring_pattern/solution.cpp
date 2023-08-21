class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n = s.length();

        for(int i = 1; i < n; i++)
            if(n % i == 0)
            {
                int j = 0;
                for(int k = 0; j < n; j++, k = (k + 1) % i)
                    if(s[j] != s[k])
                        break;

                if(j == n)
                    return true;
            }

        return false;
    }
};

/*
    a b     a b
    _ _ _ _ _ _ _ _ _ _ _ 
    i       j

    s1 s2 s3 ... sk s1 s2 s3 ... sk s1 s2 s3 ... sk
    sk sk-1 sk-2 ... s1 sk .....

*/