class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& o) {
        
		map<int, int> mp;
		for(int i = 0; i < size(nums); i++)
			mp[nums[i]] = i;
		
		for(int i = 0; i < size(o); i++)
		{
			nums[mp[o[i][0]]] = o[i][1];
			mp[o[i][1]] = mp[o[i][0]];
		}
		return nums;
    }
};
