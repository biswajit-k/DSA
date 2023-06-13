class Solution {
public:

    typedef pair<unordered_set<int>, unordered_set<int>> sets;

    int equalPairs(vector<vector<int>>& grid) {
        
        int n = grid.size(), temp;

        sets start;
        for(int i = 0; i < n; i++)
            start.first.insert(i), start.second.insert(i);

        queue<sets> q;
        q.push(start);

        for(int i = 0; i < n; i++)
        {
            int sz = q.size();
            for(int j = 0; j < sz; j++)
            {
                unordered_map<int, sets> mp;
                auto& [s1, s2] = q.front();

                for(auto& x: s1)
                {
                    temp = x;
                    mp[grid[temp][i]].first.insert(move(x));
                }   
                for(auto& x: s2)
                {
                    temp = x;
                    mp[grid[i][temp]].second.insert(move(x));
                }

                for(auto& [_, prs]: mp)
                    if(prs.first.size() && prs.second.size())
                        q.push(move(prs));

                q.pop();
            }
        }

        int ans = 0;
        while(!q.empty())
        {
            auto& [s1, s2] = q.front();
            ans += s1.size() * s2.size();
            q.pop();
        }

        return ans;
    }
};