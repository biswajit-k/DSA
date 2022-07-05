class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size(), ans = 0;
        unordered_map<int, int> len;
        
        for(auto x: nums)
            len[x] = 1;
        
        for(auto x: nums)
        {
            int curlen = 0, curnum = x;
            while(len[curnum])
            {
                int jump = len[curnum];
                
                curlen += jump;
                len[curnum] = 0;
                
                curnum -= jump;
            }
            len[x] = curlen;
            ans = max(ans, curlen);
        }
        
        return ans;
    }
};