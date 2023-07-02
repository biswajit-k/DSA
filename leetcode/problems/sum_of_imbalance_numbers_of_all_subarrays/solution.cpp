class Solution {
public:
    
    int get_diff(multiset<int>::iterator& it, multiset<int>& st) {
        
        auto i1 = st.end(), i2 = st.end();
        if(it != st.begin())
            i1 = prev(it);
        i2 = next(it);
        
        int diff = 0;
        if(i1 != st.end())
            diff += (*it - *i1 > 1);
        if(i2 != st.end())
            diff += (*i2 - *it > 1);
            
        if(i1 != st.end() && i2 != st.end())
            diff -= (*i2 - *i1 > 1);
        
        return diff;
    }
    
    
    int sumImbalanceNumbers(vector<int>& nums) {
        
        int n = nums.size();
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            multiset<int> st;
            st.insert(nums[i]);
            int curr_ans = 0;
            for(int j = i + 1; j < n; j++)
            {
                auto it = st.insert(nums[j]);
                curr_ans += get_diff(it, st);
                ans += curr_ans;
            }
        }
        
        return ans;
    }
};