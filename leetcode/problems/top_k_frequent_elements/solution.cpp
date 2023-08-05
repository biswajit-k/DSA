class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> freq;

        for(auto& x: nums)
            freq[x]++;

        priority_queue<pair<int, int>> pq;

        for(auto& [x, f]: freq)
        {
            pq.push({-f, x});

            if(pq.size() > k)
                pq.pop();
        }

        vector<int> res(k);
        for(int i = 0; i < k; i++)
        {
            res[i] = pq.top().second;
            pq.pop();
        }

        return res;
    }
};