class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        typedef long long llint;
        
        vector<llint> pref(n + 1);
        for(int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + nums[i - 1];
        
        llint ans = 1e9 + 10;
        
        for(int i = 1; i <= n; i++)
        {
            llint low = 1, high = 1e9 + 10;
            
            while(low <= high)
            {
                llint count = (low + high) / 2;

                llint full = count / n, remain = count % n;

                llint remain_start = i, remain_end = i + remain - 1;

                llint sum = pref[n] * full;

                if(remain_end <= n)
                    sum += pref[remain_end] - pref[remain_start - 1];
                else
                    sum += pref[n] + pref[remain_end % n] - pref[remain_start - 1];

                if(sum == target)
                {
                    ans = min(ans, count);
                    break;
                }
                if(sum < target)
                    low = count + 1;
                else 
                    high = count - 1;    
            }
            
        }
        
        return (ans > 1e9 ? -1 : ans);
    }
    
};