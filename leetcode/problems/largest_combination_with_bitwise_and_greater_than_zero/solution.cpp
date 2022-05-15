class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int cnt[32];
		memset(cnt, 0, sizeof(cnt));

		for(auto x: candidates)
		{
			for(int i = 0; i < 31; i++)
				cnt[i] += ((x & (1 << i)) ? 1 : 0);
		}
		int pos = 0;
		for(int i = 0;i < 31; i++)
			if(cnt[i] > cnt[pos])	pos = i;
		
		return cnt[pos];

    }
};	