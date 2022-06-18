class Solution {
public:
    
    using choice = vector<int>;
    vector<choice> ans;
    
    void helper(vector<int>& candidates, int target, int pos, choice& ary)
    {
        if(target == 0)
        {
            ans.push_back(ary);
            return;
        }
            
        
        if(pos < 0)
            return;
        
        if(candidates[pos] <= target)
        {
            ary.push_back(candidates[pos]);
            helper(candidates, target - candidates[pos], pos, ary);
            ary.pop_back();
        }
        
        helper(candidates, target, pos - 1, ary);
            
    }
    
    
    vector<choice> combinationSum(vector<int>& candidates, int target) {
        
        choice ary;
        
        helper(candidates, target, candidates.size() - 1, ary);
        
        return ans;
        
    }
};