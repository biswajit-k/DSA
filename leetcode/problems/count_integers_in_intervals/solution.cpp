class CountIntervals {
public:

	set<pair<int, int>> st;
	int cnt, inf;

    CountIntervals() {
		cnt = 0;
		inf = 1e9 + 1;
    }
    
    void add(int left, int right) {
		int taken = 0;

		if(st.empty())
		{
			st.insert({left, right});
			cnt = right - left + 1;
			return;
		}

		auto it = st.upper_bound({left, inf});
		if(it != st.begin())
			it--;
		while(it != st.end() && it->second < left)
			it++;
		while(it != st.end() && it->first <= right)
		{
			left = min(left, it->first);
			right = max(right, it->second);
			taken += it->second - it->first + 1;
			st.erase(it++);
		}
		
		cnt += right - left + 1 - taken;
		st.insert({left, right});
    }
    
    int count() {
        return cnt;
    }
};
