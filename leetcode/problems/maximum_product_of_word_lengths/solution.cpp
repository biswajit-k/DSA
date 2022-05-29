class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        
        vector<int> mat(n, 0);
        for(int i = 0; i < n ;i++)
            for(char c: words[i])
                mat[i] |= (1 << (c - 'a'));
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(!(mat[i] & mat[j]))
                    ans = max(ans, int(size(words[i]) * size(words[j])));
        
        return ans;
        
        
    }
};