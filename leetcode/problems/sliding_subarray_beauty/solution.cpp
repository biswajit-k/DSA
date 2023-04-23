class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        
        int n = nums.size();
        
        vector<int> res;
        multiset<int> st;

        multiset<int>::iterator it;
        for(int i = 0; i < n; i++)
        {
            st.insert(nums[i]);

            if(i == k - 1)
                it = next(st.begin(), x - 1);

            if(i >= k && nums[i] < *it)
                it--;
            
            if(i >= k)
            {
                if(nums[i - k] <= *it)  
                    it++;
                st.erase(st.find(nums[i - k]));
            }

            if(i >= k - 1)
                res.push_back(min(0, *it));
        }

        return res;
    }
};