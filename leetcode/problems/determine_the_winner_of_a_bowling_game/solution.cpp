class Solution {
public:
    
    int get_s(vector<int>& a) {
        
        int n = a.size(), s = 0;
        
        for(int i = 0; i < n;i++)
        {
            if(i == 0)  s += a[i];
            else if(i == 1) s += a[i - 1] == 10 ? 2 * a[i] : a[i];
            else s += a[i - 1] == 10 || a[i - 2] == 10 ? 2 * a[i] : a[i];
        }
        
        return s;
    }
    
    int isWinner(vector<int>& player1, vector<int>& player2) {
            
        int p1 = get_s(player1), p2 = get_s(player2);
        if(p1 > p2)
            return 1;
        else if(p1 == p2)
            return 0;
        return 2;
        
    }
};