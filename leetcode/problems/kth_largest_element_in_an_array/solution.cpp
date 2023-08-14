class Solution {
public:

    // recursive function to return the kth largest element in the array after partitioning it
    int partition(int l, int r, vector<int>& nums) {

        if(l == r)
            return l;

        int rand_idx = rand() % (r - l) + l;
        swap(nums[rand_idx], nums[r]);

        int i = l, j = l;

        while(j < r)
        {
            if(nums[j] > nums[r])
                swap(nums[i++], nums[j++]);
            else 
                j++;
        }

        swap(nums[r], nums[i]);
        return i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        
        int l = 0, r = nums.size() - 1;

        while(l < r)
        {
            int idx = partition(l, r, nums);
            if(idx == k - 1)
                return nums[idx];

            if(idx >= k)
                r = idx - 1;
            else 
                l = idx + 1;
        }

        return nums[l];
    }
};