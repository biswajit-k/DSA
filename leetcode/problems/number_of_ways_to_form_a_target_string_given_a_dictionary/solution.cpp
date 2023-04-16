class Solution {
public:

    const long long mod = 1e9 + 7;

    int numWays(vector<string>& words, string target) {

        int n = target.size(), w = words.size(), m = words[0].size();

        set<int> pos[26];
        unordered_map<int, int> counts[26];

        for(int i = 0; i < m; i++)
        {
            vector<int> cnt(26, 0);
            for(auto& word: words)
                cnt[word[i] - 'a']++;

            for(int j = 0; j < 26; j++)
                if(cnt[j])
                {
                    counts[j][i] = cnt[j];
                    pos[j].insert(i);
                }

        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        function<int(int, int)> helper = [&](int w_idx, int t_idx) {

            if(t_idx == n)
                return 1;

            if(w_idx == m)
                return 0;

            if(dp[w_idx][t_idx] != -1)  return dp[w_idx][t_idx];

            int c_pos = target[t_idx] - 'a';
            auto it = pos[c_pos].lower_bound(w_idx);
            
            int ways = 0;

            while(it != pos[c_pos].end())
            {
                int idx = *it, count = counts[c_pos][idx];

                int res = count * 1LL * helper(idx + 1, t_idx + 1) % mod;
                if(res == 0)
                    break;

                ways = (ways + res) % mod;
                it++;
            }
            
            return dp[w_idx][t_idx] = ways;
        };

        return helper(0, 0);
    }
};