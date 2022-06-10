class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length(), start = 0, i = 0, ans = 0;
        
        vector<bool> taken(128, 0);
        
        while(i < n)
        {
            while(taken[s[i]])
            {
                taken[s[start]] = 0;
                start++;
            }
            ans = max(ans, i - start + 1);
            taken[s[i]] = 1;
            i++;
            
        }
        
        return ans;
    }
};