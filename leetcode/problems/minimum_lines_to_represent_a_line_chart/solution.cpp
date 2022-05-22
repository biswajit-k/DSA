
class Solution {
public:
    int minimumLines(vector<vector<int>>& price) {
		if(price.size() == 1)
			return 0;
		auto cmp = [](vector<int>& a, vector<int>& b){
			return a[0] < b[0];
		};
		sort(price.begin(), price.end(), cmp);
		int cnt = 1;
		long long x1 = price[0][0], x2 = price[1][0], y1 = price[0][1], y2 = price[1][1];
		// double eps = 1e-10;

		for(int i = 2; i < price.size(); i++)
		{
			long long x3 = price[i][0], y3 = price[i][1];
			long long a1 = x3 - x1, a2 = x2 - x1, b1 = y3 - y1, b2 = y2 - y1;

			if(abs(a1 * b2 != a2 * b1))
				cnt++;
			
			x1 = x2, y1 = y2;
			x2 = x3, y2 = y3;
		}

		return cnt;
    }
};
