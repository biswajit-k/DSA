class Solution {
public:

    bool canCross(vector<int>& stones) {
        
        int destination = stones.back();
        unordered_map<int, bool> stone_exist;

        for(auto& stone_idx: stones)
            stone_exist[stone_idx] = true;

        priority_queue<int, vector<int>, greater<int>> pq;

        unordered_map<int, unordered_set<int>> jumps;

        jumps[0].insert(0);
        pq.push(0);

        while(!pq.empty())
        {
            auto pos = pq.top();
            pq.pop();

            for(auto& jump: jumps[pos])
            {
                for(int i = max(1, jump - 1); i <= jump + 1; i++)
                    if(stone_exist[pos + i] && (pos + i) <= destination)
                    {
                        if(pos + i == destination)
                            return true;
                            
                        if(jumps.count(pos + i) == 0)
                            pq.push(pos + i);
                        jumps[pos + i].insert(i);
                    }
            }

            jumps.erase(pos);
        }
   
        return false;
    }
};
