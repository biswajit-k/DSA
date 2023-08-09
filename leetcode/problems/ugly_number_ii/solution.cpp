class Solution {
public:
    int nthUglyNumber(int n) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, bool> taken;

        pq.push(1);

        for(int i = 0; i < n - 1; i++)
        {
            int x = pq.top();
            pq.pop();

            for(auto m: {2, 3, 5})
                if(x * 1LL * m <= INT_MAX && !taken.count(x * m))
                {
                    pq.push(m * x);
                    taken[m * x] = true;
                }
        }

        return pq.top();
    }
};