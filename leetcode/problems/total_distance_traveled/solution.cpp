class Solution {
public:
    int distanceTraveled(int mt, int add) {
        
        int lt = 0;
        while(mt > 0)
        {
            int out = min(5, mt);
            mt -= out;
            lt += out;
            if(out == 5 && add > 0)
                mt++, add--;
        }
        return 10 * lt;
    }
};