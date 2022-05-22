
class Solution {
public:

/* 
idea - 
-> maintain previous smaller element using stack
-> for current element keep poping prev element until it is smaller than current
	for each greater element keep summing subarrays


      p4      p3           p2          p1       i				: a[p2] < a[i] so pop until p3 is top
	-----------------------------------------------
                                a[x1]  -- 
							a[x2]   -----
						       ----------
                              at p1, (p2 - p1) values so add a[i] * (p2 - 
							  p1) for making subarray till i

	-> ans = part less than p3 + part greater than p3 till i
	-> now, at p3 : ans += ans[p3] + (pref[i] - pref[p3]) needs to be added to all subarray less than p3
	that is done by : x = (no. of subarrays less than p4) * a[p4] + ...for p3

 */

	const long long mod = 1e9 + 7;

    int totalStrength(vector<int>& a) {
		
		long long n = a.size(), x = 0;
		// prefix_sum[1...n]
		vector<long long> prefix(n + 1);
		prefix[0] = 0;
		for(int i = 1;i <= n; i++)
			prefix[i] = (a[i - 1] + prefix[i - 1]) % mod;

		stack<pair<long long, long long>> st;

		vector<long long> ans(n + 1, 0);

		for(int i = 0; i < n;i++)
		{
			long long my = a[i];

			while(!st.empty() && a[st.top().first] >= a[i])
			{
				auto [pos, sum] = st.top();
				st.pop();
				long long count = (st.empty() ? pos + 1 : pos - st.top().first);
				sum = (sum + (((prefix[i + 1] - prefix[pos + 1] + mod) % mod) * count) % mod) % mod;
				my = (my + sum) % mod;
				// if(i == 2)
				// 	deb(sub);
				x = (x - (a[pos] * count) % mod + mod) % mod;
			}

			pair<long long, long long> pr = {i, my};

			my = (my * a[i]) % mod;

			if(!st.empty())
			{
				my = (my + ans[st.top().first]) % mod;
				my = (my + (x * (prefix[i + 1] - prefix[st.top().first + 1] + mod) % mod) % mod) % mod;
			}
			
			x = (x + ((st.empty() ? i + 1 : i - st.top().first) * a[i]) % mod) % mod;
			st.push(pr);
			ans[i] = my;
		}

		long long res = 0;
		for(int i = 0; i < n;i++)
			res = (res + ans[i]) % mod;

		return res;
    }
};
