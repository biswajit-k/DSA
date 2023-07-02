class Solution {
public:
    
    typedef long long llint;
    
    bool check(int x, map<int, int>& mp) {
        
        if(mp.empty())  return true;
        
        llint low = mp.begin() -> first, high = mp.rbegin() -> first;
        llint a1 = abs(low - x), a2 = abs(high - x);
        return (a1 >= 0 && a1 <= 2 && a2 >= 0 && a2 <= 2);
    }
    
    
    long long continuousSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        
        map<int, int> mp;
        
        int i = 0, j = 1;
        mp[nums[i]]++;
        
        llint ans = 1;
        
        while(j < n)
        {
            if(check(nums[j], mp))      // todo
            {
                mp[nums[j]]++;
            }
            else 
            {
                // llint l = j - i;
                // ans += l * (l + 1) / 2;
                // cout << l * (l + 1) / 2 << ' ' << i << ' ' << j << '\n';
                while(!check(nums[j], mp))
                {
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0)
                        mp.erase(nums[i]);
                    i++;
                }

                mp[nums[j]]++;
            }
            ans += j - i + 1;
            j++;
        }
        
        
        // llint l = j - i;
        // ans += l * (l + 1) / 2;
        // cout << l * (l + 1) / 2 << ' ' << i << ' ' << j << '\n';
        // cout << '\n';
        return ans;
    }
};