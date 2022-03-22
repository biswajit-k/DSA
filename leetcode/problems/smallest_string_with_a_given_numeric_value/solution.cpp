class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,  'a');
        
        int req = k - n;
        for(int i = n - 1; i > -1; i--)
        {
            if(req <= 25)
            {
                ans[i] += req;
                break;
            }
            ans[i] += 25;
            req -= 25;
        }
        return ans;
        
    }
};