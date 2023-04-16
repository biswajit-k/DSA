class Solution {
public:
    int addMinimum(string word) {
        
        int n = word.size();
        int extra = 0, expected = 0;
        
        for(int i = 0; i < n; )
        {
            if(word[i] - 'a' == expected)
                expected++, i++;
            else 
                extra++, expected++;
            
            expected %= 3;
        }
        
        extra += (3 - expected) % 3;
        
        return extra;
    }
};