class Solution {
public:
    typedef long long llint;
    
    int minSizeSubarray(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        vector<llint> pref(2 * n, 0);
        for(int i = 1; i < pref.size(); i++)  
            pref[i] = pref[i - 1] + (i > n ? nums[i - (n + 1)] : nums[i - 1]);
        
        
        llint len = 1e9 + 11;
        
        for(int i = 1; i <= n; i++)
        {
            llint l = 1, r = 1e9 + 10;
            
            while(l <= r)
            {
                llint mid = (l + r) / 2;
                
                llint sum = pref[n] * (mid / n) + ((mid % n) ? (pref[(mid % n) + i - 1] - pref[i - 1]) : 0);
                
                if(sum == target)
                {
                    len = min(len, mid);
                    break;
                }
                if(sum < target)
                    l = mid + 1;
                else
                    r = mid - 1;
                
            }
            
            
        }
        
        return (len > 1e9 + 1 ? -1 : len);
    }
};