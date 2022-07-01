class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int n = boxTypes.size(), ans = 0;
        
        auto cmp = [](vector<int>& a, vector<int>& b){
            return a[1] > b[1];  
        };
        
        sort(begin(boxTypes), end(boxTypes), cmp);
        
        for(int i = 0; i < n && truckSize; i++)
        {
            int taken = min(truckSize, boxTypes[i][0]);
            ans += taken * boxTypes[i][1];
            
            truckSize -= taken;
        }
        
        return ans;
    }
};