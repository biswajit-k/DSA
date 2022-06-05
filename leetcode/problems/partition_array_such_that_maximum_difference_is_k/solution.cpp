
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
		int c = 0, s = 0, n = nums.size();

		for(int i = 1; i < n;i++)
		{
			if(nums[i] - nums[s] > k)
			{
				c++;
				s = i;
			}
		}
		c++;
		return c;

    }
};