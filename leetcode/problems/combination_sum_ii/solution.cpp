class Solution {
public:

    void helper(int idx, vector<int>& res, int target, vector<int>& candidates, unordered_map<int, int>& freq, vector<vector<int>>& ans) {

        if(target == 0) 
        {
            ans.push_back(res);
            return;
        }
        if(idx == candidates.size())
            return;
        
        helper(idx + 1, res, target, candidates, freq, ans);

        int curr_candidate = candidates[idx], v = 0;
        for(int i = 0; i < freq[curr_candidate]; i++)
        {
            v += curr_candidate;
            if(target - v < 0)  break;

            res.push_back(curr_candidate);
            helper(idx + 1, res, target - v, candidates, freq, ans);
        }

        while(!res.empty() && res.back() == curr_candidate)  res.pop_back();
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        unordered_map<int, int> freq;
        vector<vector<int>> ans;
        vector<int> res;

        for(auto& x: candidates)    freq[x]++;

        sort(begin(candidates), end(candidates));
        candidates.resize(unique(begin(candidates), end(candidates)) - candidates.begin());

        helper(0, res, target, candidates, freq, ans);

        return ans;
    }
};


/*
    funciton helper(idx, curr_vec, req_sum, candidates, ans):

        if(req_sum == 0)    ans.push(curr_vec)
        if(idx == N)    return

        helper(idx + 1, curr_vec, req_sum, candidates, ans)

        for i = 1 to frequency_of_candidates[idx]:

            curr_vec.push(candidates[idx])

            if(req_sum - candidates[idx] < 0)   break

            helper(idx + 1, curr_vec, req_sum - candidates[idx], candidates, ans)

        while(curr_vec.back() == candidates[idx])
            curr_vec.pop()
        
*/