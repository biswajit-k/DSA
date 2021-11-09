
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, h = int(1e5);
        while(l != h)
        {
            int mid = (l + h)/2;
            
            int miqty = 0;
            for(auto x: quantities)
                miqty += int(ceil(x/double(mid)));

            if(miqty > n)
                l = mid + 1;
            else 
                h = mid;

        }
        return l;
    }
};