class Solution {
public:
    
    bool check(int start, vector<int>& derived) {
        
        int curr = start;
        for(int i = 0; i < size(derived); i++)
            curr ^= derived[i];
        return curr == start;
    }
    
    
    bool doesValidArrayExist(vector<int>& derived) {
        
        return check(0, derived) || check(1, derived);
        
    }
};