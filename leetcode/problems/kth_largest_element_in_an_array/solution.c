
void merge_sort(int l, int r, int* nums) {

    if(l == r)
        return;
    int mid = (l + r) / 2;
    merge_sort(l, mid, nums);
    merge_sort(mid + 1, r, nums);

    int temp[r - l + 1];
    int i = l, j = mid + 1, k = 0;

    while(i <= mid && j <= r)
        temp[k++] = (nums[i] < nums[j] ? nums[i++] : nums[j++]);

    while(i <= mid)
        temp[k++] = nums[i++];
    while(j <= r)
        temp[k++] = nums[j++];
    
    for(i = l; i <= r; i++)
        nums[i] = temp[i - l];
}

int findKthLargest(int* nums, int n, int k){
    
    merge_sort(0, n - 1, nums);

    return nums[n - k];
}