
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
		sort(special.begin(), special.end());
		int ans = 0, n = special.size();

		for(int i = 0; i < n - 1; i++)
			ans = max(ans, special[i + 1] - special[i] - 1);
		
		if(n)
		{
			ans = max(ans, special[0] - bottom);
			ans = max(ans, top - special.back());
		}
		return ans;
    }
};