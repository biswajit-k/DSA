class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int add) {
        int n = capacity.size();
		vector<int> ans(n);
		for(int i = 0;i < n; i++)
			ans[i] = capacity[i] - rocks[i];
		sort(ans.begin(), ans.end());
		int cnt = 0;
		for(int i = 0;i < n; i++)
		{
			if(!ans[i])
			{
				cnt++;
				continue;
			}
			if(add >= ans[i])
			{
				add -= ans[i];
				cnt++;
			}
			else 
				break;
		}
		return cnt;

    }
};