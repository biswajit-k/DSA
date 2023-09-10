class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        if(sx == fx && sy == fy)
        {
            return (t == 1 ? false : true);
        }
        
        int vx = fx >= sx ? 1 : -1;
        int vy = fy >= sy ? 1 : -1;
        
        int move = min(abs(sx - fx), abs(sy - fy));
        
        sx += move * vx;
        sy += move * vy;
        
        move += abs(sx - fx) + abs(sy - fy);
        
        return move <= t;
    }
};