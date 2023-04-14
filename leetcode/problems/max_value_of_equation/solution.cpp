class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        
        int n = points.size(), ans = -1e9, idx = 1;
        deque<int> max_val_idx;

        for(int i = 0; i < n; i++)
        {
            int x = points[i][0], y = points[i][1];

            while(idx < n && points[idx][0] - x <= k)
            {
                while(!max_val_idx.empty())
                {
                    int p = max_val_idx.back();
                    if(points[p][0] + points[p][1] > points[idx][0] + points[idx][1])
                        break;
                    max_val_idx.pop_back();
                }
                max_val_idx.push_back(idx);
                idx++;
            }

            while(!max_val_idx.empty() && max_val_idx.front() <= i)
                max_val_idx.pop_front();

            if(!max_val_idx.empty())
            {
                int p = max_val_idx.front();
                ans = max(ans, y - x + points[p][0] + points[p][1]);
            }
        }

        return ans;
    }
};