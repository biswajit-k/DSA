class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        int n = arr.size();

        auto mi = min_element(begin(arr), end(arr));
        swap(arr[mi - begin(arr)], arr[0]);

        int d = *min_element(begin(arr) + 1, end(arr)) - arr[0];

        bool equal = true;
        for(int i = 0; i < n - 1; i++)
            equal &= arr[i] == arr[i + 1];

        if(d == 0)
            return (equal ? true : false);

        for(int i = 1; i < n; i++)
        {
            int idx = (arr[i] - arr[0]) / d;
            while(idx != i)
            {
                if(idx >= n || (arr[idx] - arr[0]) / d == idx)
                    return false;
                swap(arr[i], arr[idx]);
                idx = (arr[i] - arr[0]) / d;
            }
        }

        return true;
    }
};