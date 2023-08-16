class Solution {
public:

    void operation(int i, vector<int>& nums, deque<int>& q) {
        while(!q.empty() && nums[q.back()] <= nums[i])
            q.pop_back();
        q.push_back(i);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        deque<int> q;

        for(int i = 0; i < k - 1; i++)
            operation(i, nums, q);

        for(int i = k - 1; i < nums.size(); i++)
        {
            operation(i, nums, q);

            if(q.front() < i - k + 1)
                q.pop_front();

            ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};


// 1, 3, -1, -3, 5, 3, 6, 7