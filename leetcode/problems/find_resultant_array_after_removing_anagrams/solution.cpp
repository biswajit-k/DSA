
class Solution {
public:

	bool check(string& a, string& b)
	{
		int f1[36], f2[52];
		memset(f1, 0, sizeof(f1));
		memset(f2, 0, sizeof(f2));
		for(auto c: a)	f1[c - 'a']++;
		for(auto c: b)	f2[c - 'a']++;

		for(int i = 0; i < 28; i++)
			if(f1[i] != f2[i])
				return 0;

		return 1;
	}

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
		for(auto word: words)
		{
			if(ans.empty())
			{
				ans.push_back(word);
				continue;
			}
			else if(check(ans.back(), word))
				continue;

			ans.push_back(word);
		}
		return ans;
    }
};
