class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        list<pair<int, int>> lst;
        for(int i = 0; i < stones.size(); i++)
            lst.push_back({stones[i][0], stones[i][1]});

        queue<pair<int, int>> q;
        int ans = 0;

        while(!lst.empty())
        {
            q.push(*(lst.begin()));
            lst.erase(lst.begin());

            while(!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                for(auto it = lst.begin(); it != lst.end();)
                {
                    auto [xx, yy] = *it;
                    if(xx == x || yy == y)
                    {
                        q.push(*it);
                        it = lst.erase(it);
                    }
                    else 
                        it++;
                }
            }

            ans++;
        }

        return stones.size() - ans;
    }
};