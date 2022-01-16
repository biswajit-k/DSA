class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int sm = 0;
        for(auto x: nums)
                sm += x;
        if(sm % 2 == 1)
            return false;
        set<int> s, ts;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > sm / 2 || s.find(sm / 2) != s.end())
                    break;
            ts = s;
            s.insert(nums[i]);
            for(auto it = ts.begin(); it != ts.end(); it++)
                s.insert(nums[i] + *it);
            
        }
        if(s.find(sm / 2) != s.end())
            return true;
        return false;
        
    }
};