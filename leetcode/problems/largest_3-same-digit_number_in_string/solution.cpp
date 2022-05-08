class Solution {
public:
bool check(string& s)
{
	if((s[0] == s[1]) && (s[0] == s[2]))
		return 1;
	return 0;
}

string largestGoodInteger(string num) {
    
	string ans = "", cur = "";
	int mx = 0;

	if(num.length() < 3)	return "";
	cur = string(num.begin(), num.begin() + 2);

	for(int i = 2; i < num.length(); i++)
	{
		cur += num[i];
		if(cur == "000")
			ans = cur;
		if(check(cur) && stoi(cur) > mx)
		{
			mx = stoi(cur);
		}
		cur = string(cur.begin() + 1, cur.begin() + 3);
	}

	if(mx == 0)
		return ans;
    else 
        ans = "";        
	while(mx)
	{
		ans += '0' + mx % 10;
		mx /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;

}
};