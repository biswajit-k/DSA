class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        
        int n = nums.size();
        
        vector<int> res;
        if(k == 1)
        {
            res = nums;
            for(int i = 0; i < n; i++)
                if(res[i] > 0)
                    res[i] = 0;
            return res;
        }
        multiset<int> st;
        queue<multiset<int>::iterator> q;
        int pos = 0;
        for(; pos < k; pos++)
        {
            auto i = st.insert(nums[pos]);
            q.push(i);
        }
            
        
        auto it = st.begin();
        for(int i = 0; i < x - 1; i++)
            it++;
        
        res.push_back(min(0, *it));
        for(; pos < n; pos++)
        {
            auto last = q.front();
            q.pop();
            int ins = nums[pos];
            
            auto it2 = it;
            if(*last <= *it)
                it2++;
            
            st.erase(last);
            
            auto i = st.insert(ins);
            q.push(i);
            if(it2 == st.end() || ins < *it2)
                it = --it2;
            else 
                it = it2;
            res.push_back(min(0, *it));
        }
        
        return res;
    }
};