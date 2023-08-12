class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size();

        int pos = 1;
        priority_queue<int> pq;

        for(; pos < n; pos++)
        {
            int h = heights[pos] - heights[pos - 1];

            if(h <= 0)  continue;
            if(bricks < h && ladders == 0)  break;

            bricks -= h;
            pq.push(h);

            if(bricks < 0)
            {
                int mx_height = pq.top();
                pq.pop();

                bricks += mx_height;
                ladders--;
            }
        }

        return pos - 1;
    }
};