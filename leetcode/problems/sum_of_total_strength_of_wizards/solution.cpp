
class Solution {
public:

	const long long mod = 1e9 + 7;

    int totalStrength(vector<int>& a) {
		
		long long n = a.size(), x = 0;

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
