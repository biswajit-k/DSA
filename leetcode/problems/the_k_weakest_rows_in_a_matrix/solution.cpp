
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		vector<pair<int, int>> vc;
		int n = mat.size(), m = mat[0].size(), i = 0;
		for(auto ary: mat)
		{
			int c = 0;
			for(auto x: ary)
			{
				if(x)	c++;
				else	break;
			}
			vc.push_back({c, i});
			i++;
		}
		auto cmp = [](pair<int, int> a, pair<int, int> b){
			if(a.first < b.first)
				return true;
			if(a.first > b.first)
				return false;
			return (a.second < b.second);
		};
		sort(vc.begin(), vc.end(), cmp);
		vector<int> ans(k);
		for(int j = 0; j < k; j++)
			ans[j] = vc[j].second;
		return ans;
    }
};
