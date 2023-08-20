class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, vector<int>> same;
        
        for(int i = 0; i < n; i++)
            same[nums[i]].push_back(i);
        
        int ans = 0;
        for(auto& [_, v]: same)
        {
            int i = 0, j = 1, removed = 0, len = 1;
            ans = max(ans, len);
            
            while(j < v.size())
            {
                removed += v[j] - v[j - 1] - 1;
                len++;
                while(removed > k)
                {
                    removed -= v[i + 1] - v[i] - 1;
                    i++;
                    len--;
                }
                ans = max(ans, len);
                
                j++;
            }
        }
        
        return ans;
    }
};