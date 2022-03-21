class Solution {
public:
     vector<int> partitionLabels(string s) {
	int end[53] = {}, n = s.length();

	for(int i = 0; i < n;i++)
		end[s[i] - 'a'] = i;
	
	int cur = 0, stoppage = end[s[0] - 'a'], c_len = 1;
	vector<int> values;


	while(cur < n)
	{
		stoppage = max(stoppage, end[s[cur] - 'a']);
 
		while(stoppage < n && cur < stoppage)
		{
			stoppage = max(stoppage, end[s[cur] - 'a']);
			c_len++;
			cur++;
		}

		values.push_back(c_len);
		c_len = 1;

		cur++;
	}

	return values;
}
};