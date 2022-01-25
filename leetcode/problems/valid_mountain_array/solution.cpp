class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int cur = arr[0], pos = 1, n = arr.size();
        
        while(pos < n && arr[pos] > cur)
        {
            cur = arr[pos];
            pos++;
        }
        if(pos == 1 || pos == n)
            return false;

        while(pos < n && arr[pos] < cur)
        {
            cur = arr[pos];
            pos++;
        }
        if(pos == n)
            return true;
        return false;
    }
};