class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> freq;

        for(auto& x: nums)
            freq[x]++;

        //invariant: smallest position s.t subarrays ending at this idx have all elements of nums
        int j = n - 1;

        while(freq[nums[j]] - 1 > 0)
        {
            freq[nums[j]]--;
            j--;   
        }

        int complete_subarrays = 0;

        for(int i = 0; i < n && j < n; i++)
        {
            complete_subarrays += n - j;

            freq[nums[i]]--;
            while(j < n - 1 && freq[nums[i]] == 0)
            {
                j++;
                freq[nums[j]]++;
            }
            if(j == n - 1 && freq[nums[i]] == 0)
                break;

        }

        return complete_subarrays;
    }
};