class Solution {
public:

    const int inf = 88888888;

    int doit(vector<int>& cookies, int k)
    {
        int l = *max_element(begin(cookies), end(cookies)), r = accumulate(begin(cookies), end(cookies), 0), ans = inf;

        while(l <= r)
        {
            int mid = (l + r) / 2;

            int partition = 1, curr = 0;

            for(int i = 0; i < cookies.size(); i++)
            {
                if(curr + cookies[i] <= mid)
                    curr += cookies[i];
                else 
                {
                    partition++;
                    curr = cookies[i];
                }
            }

            if(partition > k)
                l = mid + 1;
            else 
            {
                r = mid - 1;
                ans = min(ans, mid);
            }

        }

        return ans;

    }

    int distributeCookies(vector<int>& cookies, int k) {
        
        int ans = inf; 

        sort(begin(cookies), end(cookies));

        do{
            ans = min(ans, doit(cookies, k));

        } while(next_permutation(begin(cookies), end(cookies)));    

        return ans;


    }
};