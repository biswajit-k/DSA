class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int, int> freq;
        for(auto& x: arr)   freq[x]++;
        
        int nums[size(freq)], sz = size(freq);
        
        auto it = begin(freq);
        for(int i = 0; it != freq.end(); i++, it++)
            nums[i] = it -> second;
        
        sort(nums, nums + sz, greater<int>());
        
        int cnt = 0, pos = 0, n = arr.size();
        
        for(int i = 0; i < sz && cnt < n / 2; i++, pos++)
            cnt += nums[i];
        
        return pos;
    }
};