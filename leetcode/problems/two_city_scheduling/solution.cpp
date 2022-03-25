class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

	auto cmp = [](vector<int>& a, vector<int>& b){
		return (a[0] - a[1]) > (b[0] - b[1]);
	};
	sort(costs.begin(), costs.end(), cmp);

	int total = 0, n = (int)costs.size() / 2;
	for(int i = 0; i < n; i++)
		total += costs[i][1];
	for(int i = n; i < 2 * n; i++)
		total += costs[i][0];
	
	return total;

}
};