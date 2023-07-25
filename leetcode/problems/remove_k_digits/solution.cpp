class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.length(), i = 0, remove = k;

        for(int j = 1; j < n; j++)
        {
            while(i > -1 && remove && num[j] < num[i])
            {
                remove--;
                i--;
            }
            i++;
            num[i] = num[j];
        }

        i = 0;
        while(i < (n - k) && num[i] == '0')
            i++;
        
        if(n - k - i == 0)
            return "0";

        return num.substr(i, n - k - i);
    }
};