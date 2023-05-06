class Solution {
public:

    const int mod = 1e9 + 7;

    int mod_expo(int x, int n) {

        if(n == 0)
            return 1;
        if(n == 1)
            return x;

        long long res = mod_expo(x, n / 2);
        res = (res * res) % mod;
        if(n % 2 == 1)
            res = (res * x) % mod;

        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        
        unordered_map<int, int> cnt;
        for(auto& x: nums)
            cnt[x]++;
           
        nums.resize(int(cnt.size()));
        int i = 0;
        for(auto& [x, _]: cnt)  nums[i++] = x;
        
        sort(begin(nums), end(nums));

        for(int i = 1; i < nums.size(); i++)
            cnt[nums[i]] += cnt[nums[i - 1]];

        int ans = 0;
        for(int i = 0, j = nums.size() - 1; i <= j; i++)
        {

            while(j >= i && nums[i] + nums[j] > target)
                j--;
            if(j < i)
                break;

            int curr_cnt = i ? cnt[nums[i]] - cnt[nums[i - 1]] : cnt[nums[i]];
            int greater = cnt[nums[j]] - cnt[nums[i]];

            int res = (mod_expo(2, curr_cnt) - 1) * 1LL * mod_expo(2, greater) % mod;
            ans += res;
            ans %= mod;
        }

        return ans;
    }
};