class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& C) {
        
        int x = C[0][0] - C[1][0], y = C[0][1] - C[1][1];
        int neg = (x > 0) ^ (y > 0);

        x = abs(x), y = abs(y);

        int gc = gcd(x, y);
        x /= gc, y /= gc;

        for(int i = 2; i < C.size(); i++)
        {
            int xx = C[i][0] - C[i - 1][0], yy = C[i][1] - C[i - 1][1];
            int is_neg = (xx > 0) ^ (yy > 0);

            xx = abs(xx), yy = abs(yy);
            gc = gcd(xx, yy);
            xx /= gc, yy /= gc;

            if((y == 0 && yy == 0) || (x == 0 && xx == 0))
               continue;

            if(xx != x || yy != y || is_neg != neg)
                return false;
        }

        return true;
    }
};