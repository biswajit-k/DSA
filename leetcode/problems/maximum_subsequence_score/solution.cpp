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

        for(int i = n - 1, j = 0; j < k - 1; i--, j++)
        {
            sum += S[i].first;
            marked.insert(S[i].second);
        }

        // iterate product array to take num for product
        for(int i = 0, j = n - k; i < n && j >= 0; i++)
        {
            auto [x, idx] = P[i];
            if(!marked.count(idx))
            {
                sum += nums1[idx];
                marked.insert(idx);
            }
            else 
            {
                while(j >= 0 && marked.count(S[j].second))
                    j--;
                if(j < 0)
                    break;
                sum += S[j].first;
                marked.insert(S[j].second);
            }
            ans = max(ans, sum * x);
            sum -= nums1[idx];
        }

        return ans;
    }
};