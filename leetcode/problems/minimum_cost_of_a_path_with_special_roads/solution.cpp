class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& sp) {
        
        int sx = start[0], sy = start[1], tx = target[0], ty = target[1], ans = abs(sx - tx) + abs(ty - sy);
        
        sp.push_back({tx, ty, tx, ty, 0});
        int n = sp.size();
        for(int i = 0; i < n; i++)
            sp[i][4] = min(sp[i][4], abs(sp[i][0] - sp[i][2]) + abs(sp[i][1] - sp[i][3]));
        
        vector<int> dis(n);
        for(int i = 0; i < n; i++)
            dis[i] = abs(sx - sp[i][0]) + abs(sy - sp[i][1]) + sp[i][4];
        
        int change = 1;
        while(change)
        {
            change = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                    if(i != j)
                    {
                        int cost = dis[j] + abs(sp[j][2] - sp[i][0]) + abs(sp[j][3] - sp[i][1]) + sp[i][4];
                        if(cost < dis[i])
                        {
                            change = 1;
                            dis[i] = cost;
                        }
                    }
            }
            
        }
        ans = dis.back();
        
        return ans;
    }
};