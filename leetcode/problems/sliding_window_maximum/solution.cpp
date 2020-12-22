class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        int mx=INT_MIN,i=0;
        vector<int> ans;
        for(i=0;i<k;i++){
            
            //remove elements smaller than the current on left 
            while(!d.empty() && nums[d.back()]<=nums[i]) d.pop_back();
            d.push_back(i);
        }
        ans.push_back(nums[d.front()]);
        
        for(;i<nums.size();i++){
            //remove elements not in window
            while(!d.empty() && d.front()<=i-k) d.pop_front();
            
            //remove elemnts smaller than the current on left
            while(!d.empty() && nums[d.back()]<=nums[i]) d.pop_back();
            
            //add the current element and store answer
            d.push_back(i);
            ans.push_back(nums[d.front()]);
            
        }
        
        
        return ans;}};