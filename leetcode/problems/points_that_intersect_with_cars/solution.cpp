class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        
        int n = nums.size(), pts = 0;
        unordered_set<int> taken;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = nums[i][0]; j <= nums[i][1]; j++)
                if(!taken.count(j))
                {
                    taken.insert(j);
                    pts++;
                }
        }
        
        return pts;
    }
};