class Solution {
public:
    
    int get_first(int x) {
        
        while(x > 9)    x /= 10;
        return x;
    }
    
    int countBeautifulPairs(vector<int>& nums) {
        
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
            {
                if(gcd(get_first(nums[i]), nums[j] % 10) == 1)
                    ans++;
            }
        
        return ans;
    }
};