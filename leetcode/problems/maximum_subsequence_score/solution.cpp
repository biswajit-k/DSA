class Solution {
public:

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        vector<pair<int, int>> S(n), P(n);

        for(int i = 0; i < n; i++)
        {
            S[i] = {nums1[i], i};
            P[i] = {nums2[i], i};
        }

        sort(begin(S), end(S));
        sort(begin(P), end(P));

        // take best sum
        long long sum = 0, ans = 0;
        unordered_set<int> marked;

        for(int i = 0; i < k - 1; i++)
        {
            auto [x, idx] = S.back();
            sum += x;
            marked.insert(idx);
            S.pop_back();
        }

        // iterate product array to take num for product
        for(int i = 0; i < n && !S.empty(); i++)
        {
            auto [x, idx] = P[i];
            if(!marked.count(idx))
            {
                sum += nums1[idx];
                marked.insert(idx);
            }
            else 
            {
                while(!S.empty() && marked.count(S.back().second))
                    S.pop_back();
                if(S.empty())
                    break;
                sum += S.back().first;
                marked.insert(S.back().second);
            }
            ans = max(ans, sum * x);
            sum -= nums1[idx];
        }

        return ans;
    }
};