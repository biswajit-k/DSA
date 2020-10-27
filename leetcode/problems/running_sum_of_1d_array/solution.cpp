class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> x;
        int s=0;
        
        for(int i=0;i<nums.size();++i){
            
            s+=nums[i];
            x.push_back(s);
            
        }
        return x;
        
    }
};