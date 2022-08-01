class NumArray {
public:
    
    vector<int> bit;
    int sz;
    
    NumArray(vector<int>& nums) {
        
        bit.reserve(size(nums) + 1);
        
        bit.push_back(0);
        for(auto& x: nums)
            bit.push_back(x);
        
        sz = size(nums);
        
        for(int i = 1; i <= sz; i++)
        {
            int idx = i + (i & (-i));
            if(idx <= sz)
                bit[idx] += bit[i];
        }   
    }
    
    void add(int idx, int val) {
        for(idx; idx <= sz; idx += (idx & (-idx)))
            bit[idx] += val;
    }
    
    int prefix_sum(int idx) {
        int sum = 0;
        for(idx; idx > 0; idx -= (idx & (-idx)))
            sum += bit[idx];
        return sum;
    }
    
    void update(int index, int val) {
        add(index + 1, val - sumRange(index, index));
    }
    
    int sumRange(int l, int r) {
        return prefix_sum(r + 1) - prefix_sum(l);   
    }
};