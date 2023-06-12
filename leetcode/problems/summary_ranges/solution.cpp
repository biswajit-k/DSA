class Solution {
public:

    string get_range(int a, int b) {
        string res;

        if(a == b)  res = to_string(a);
        else    res = to_string(a) + "->" + to_string(b);

        return res;
    }

    vector<string> summaryRanges(vector<int>& nums) {
        
        if(nums.empty())
            return vector<string>();

        int n = nums.size(), start = nums[0];
        vector<string> res;

        for(int i = 1; i < n; i++)
            if(nums[i] != nums[i - 1] + 1)
            {
                res.push_back(get_range(start, nums[i - 1]));
                start = nums[i];
            }

        res.push_back(get_range(start, nums.back()));

        return res;
    }
};