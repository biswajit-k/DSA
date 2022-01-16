class Solution {
public:
    const int inf = 3e4 + 4;
    
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        
        int cl = -inf, i = 0, dis = -1;
        
        while(i < n)
        {
            if(seats[i] == 1)
            {
                if(cl == -inf)
                    dis = i;
                else
                {
                    int mid = (i + cl) / 2;
                    dis = max(dis, min(i - mid, mid - cl));
                }
                cl = i;    
            }
            
            i++;
        }
        dis = max(dis, n - cl - 1);
        return dis;
        
    }
};