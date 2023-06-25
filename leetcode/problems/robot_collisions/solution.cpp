class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& P, vector<int>& H, string D) {
        
        int n = P.size();
        vector<vector<int>> robots(n);
        for(int i = 0; i < n;i++)
        {
            vector<int> vc = {P[i], H[i], D[i], i};
            robots[i] = vc;
        }
            

        sort(begin(robots), end(robots));
        
        stack<vector<int>> left;
        vector<int> ans(n);
        
        
        for(int i = n - 1; i > -1; i--)
        {
            int h = robots[i][1], idx = robots[i][3];
            char dir = char(robots[i][2]);
            
            if(dir == 'L')
            {
                left.push(robots[i]);
                continue;
            }
            
            while(!left.empty() && h)
            {
                int rob_h = left.top()[1], rob_idx = left.top()[3];
                char rob_dir = char(left.top()[2]);
                
                if(rob_h < h)
                {
                    h--;
                    rob_h = 0;
                }
                else if(rob_h > h)
                {
                    rob_h--;
                    h = 0;
                }
                else 
                {
                    h = 0;
                    rob_h = 0;
                }
                if(rob_h == 0)
                {
                    ans[rob_idx] = 0;
                    left.pop();
                }
                else
                    left.top()[1] = rob_h;
                
            }
            ans[idx] = h;
        }
        while(!left.empty())
        {
            int idx = left.top()[3], h = left.top()[1];
            ans[idx] = h;
            left.pop();
        }
        
        vector<int> res;
        for(int i = 0; i < n; i++)
            if(ans[i])
                res.push_back(ans[i]);
        
        return res;
    }
};