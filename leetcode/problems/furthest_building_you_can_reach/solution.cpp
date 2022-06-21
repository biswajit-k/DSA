class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size(), i = 1;
        priority_queue<int> pq;
        
        for(; i < n ; i++)
        {
            if(heights[i] - heights[i - 1] <= 0)
                continue;
            
            pq.push(heights[i - 1] - heights[i]);
            if(ladders)
                ladders--;
            else
            {
                int ht = pq.top();
                if(-ht > bricks)
                    break;
                pq.pop();
                bricks += ht;
            }
            
        }
        return i - 1;
    }
};