class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int sub = 0;
        queue<pair<int, int>> st;
        for(int i = 0; i < n; i++)
        {
            if(!st.empty() && st.front().first == i)
            {
                sub -= st.front().second;
                st.pop();
            }
            nums[i] -= sub;
            if(nums[i] == 0)
                continue;
            
            if(nums[i] < 0 || i + k > n) return false;
            sub += nums[i];
            st.push({i + k, nums[i]});
            
        }
        
        return true;
        
    }
};