class Solution {
public:

    const int inf = 1e8;

    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        for(int i = 0; i < tasks.size(); i++)
            freq[tasks[i] - 'A']++;

        int sz = 0;
        for(int i = 0; i < 26; i++)
            if(freq[i])
                freq[sz++] = freq[i];
        freq.resize(sz);

        vector<int> available(sz, 0);

        int tasks_left = tasks.size(), t = 0, min_available_time = 0, idx;

        while(tasks_left)
        {
            idx = -1;
            min_available_time = inf;

            for(int i = 0; i < sz; i++)
            {
                min_available_time = min(min_available_time, available[i]);
                if(available[i] <= t && (idx == -1 || freq[idx] < freq[i]))
                    idx = i;
            }
            if(idx == -1)
            {
                t = min_available_time;
                continue;
            }

            freq[idx]--;    t++;    tasks_left--;
            available[idx] = t + n;

            if(freq[idx] == 0)
            {
                freq.erase(freq.begin() + idx);
                available.erase(available.begin() + idx);
                sz--;
            }
        }

        return t;
    }
};