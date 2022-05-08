class Solution {
public:

    int countTexts(string pressedKeys) {

		const long long mo = 1e9 + 7;
		vector<int> three(100005), four(100005), split;
		long long ans = 1;
		three[0] = 1, four[0] = 1;

		for(int i = 1; i <= 100002; i++)
		{
			for(int j = 1; j < 4; j++)
				if(i - j < 0)
					break;
				else 
					three[i] = (three[i] + three[i - j]) % mo;
		}
		for(int i = 1; i <= 100002; i++)
		{
			for(int j = 1; j < 5; j++)
				if(i - j < 0)
					break;
				else 
					four[i] = (four[i] + four[i - j]) % mo;
		}

		char cur = pressedKeys[0];
		int cnt = 1;
		for(int i = 1; i < pressedKeys.length(); i++)
		{
			char c = pressedKeys[i];
			
			if(c != cur)
			{
				long long v = (cur == '7' || cur == '9') ? four[cnt] : three[cnt];
				// deb(v);
				ans = (ans * v) % mo;
				cnt = 1;
				cur = c; 
			}
			else 
				cnt++;
		}
		if(cnt)
		{
			long long v = (cur == '7' || cur == '9') ? four[cnt] : three[cnt];
			ans = (ans * v) % mo;
		}
		return ans;

    }
};
