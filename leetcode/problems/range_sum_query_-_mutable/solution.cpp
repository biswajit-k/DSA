class NumArray {
    
public:
    
    int block_sz;
    int* ary, *sum;
    
    int get_block(int i)
    {
         return i / block_sz;
    }
    
    NumArray(vector<int>& nums) {
        
        int n = nums.size();
        block_sz = sqrt(n);
        ary = new int[n];
        for(int i = 0; i < n; i++)  ary[i] = nums[i];
        
        sum = new int[get_block(n - 1) + 1];
        
        
        
        int s = 0, pos = 0;
        for(int i = 0; i < n; i++)
            if(!(i % block_sz) && i)
            {
                sum[pos] = s;
                s = ary[i];
                pos++;
            }
            else s += ary[i];
        
        sum[pos] = s;
        
    }
    
    void update(int i, int val) {
        
        int block = get_block(i);
        sum[block] += val - ary[i];
        ary[i] = val;
    }
    
    int sumRange(int left, int right) {
        
        int l = get_block(left), r = get_block(right);
        
        int ans = 0;
        
        if(l == r)
            for(int i = left; i <= right; i++)   ans += ary[i];
        
        else 
        {
            for(int i = left; get_block(i) == l; i++)   ans += ary[i];
            
            for(int i = l + 1; i < r; i++)  ans += sum[i];
                
            for(int i = right; get_block(i) == r; i--)  ans += ary[i];

        }
            
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */