class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> count(n, 0), dup(n);

        iota(begin(dup), end(dup), 0);
        
        function<void(int, int)> merge_sort = [&](int l, int r) {

            if(l == r)
                return;
            
            int m = (l + r) / 2;
            merge_sort(l, m);
            merge_sort(m + 1, r);

            vector<int> res(r - l + 1);

            int i = l, j = m + 1, k = 0;
            while(i <= m && j <= r)
            {
                if(nums[dup[i]] <= nums[dup[j]])
                {
                    res[k++] = dup[i];
                    count[dup[i]] += r - j + 1;
                    i++;
                }
                else
                    res[k++] = dup[j++];
            }

            while(j <= r)
                res[k++] = dup[j++];
            while(i <= m)
                res[k++] = dup[i++];

            for(int i = l; i <= r; i++)
                dup[i] = res[i - l];

        };

        merge_sort(0, n - 1);
        for(int i = 0; i < n; i++)
            count[i] = n - i - 1 - count[i];

        return count;
    }
};