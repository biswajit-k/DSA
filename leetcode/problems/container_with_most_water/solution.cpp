class Solution {
public:
    int maxArea(vector<int>& H) {
        
        int n = H.size();
        int ans = 0;

        for(int i = 0, j = n - 1; i < j; )
        {
            ans = max(ans, (j - i) * min(H[i], H[j]));

            if(H[i] < H[j])
                i++;
            else if(H[i] > H[j])
                j--;
            else 
                i++, j--;
        }

        return ans;
    }
};