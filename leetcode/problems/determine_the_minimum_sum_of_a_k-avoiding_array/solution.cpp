class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0;
        unordered_set<int> not_take;
        
        for(int curr = 1, taken = 0; taken < n; curr++)
        {
            if(not_take.count(curr))
                continue;
            
            sum += curr;
            not_take.insert(k - curr);
            taken++;
        }
        
        return sum;
    }
};