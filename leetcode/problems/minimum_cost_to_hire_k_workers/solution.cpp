class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        int n = quality.size();
        
        vector<int> wage_per_qty_idx(n);
        iota(begin(wage_per_qty_idx), end(wage_per_qty_idx), 0);

        sort(begin(wage_per_qty_idx), end(wage_per_qty_idx), [&](int i1, int i2) {
            return wage[i1]/double(quality[i1]) < wage[i2]/double(quality[i2]);
        });

        int total_qty = 0;
        double ans = 1e9;

        priority_queue<int> pq;

        for(int i = 0; i < n; i++)
        {
            int idx = wage_per_qty_idx[i];

            if(i > k - 1)
            {
                int qty = pq.top();
                pq.pop();
                total_qty -= qty;
            }
            if(i >= k - 1)
            {
                double curr_ans = (double)wage[idx] * (total_qty) / quality[idx] + wage[idx];
                ans = min(ans, curr_ans);
            }
            pq.push(quality[idx]);
            total_qty += quality[idx];
        }

        return ans;
    }
};