class Solution {

private:

    long long get_sum(int n, int x) {

        long long res = 0;
        if(x > n)
            res = n * 1LL * x - n * 1LL * (n + 1) / 2;
        else 
            res = x * 1LL * (x - 1) / 2 + n - x + 1;

        return res;
    }


public:
    int maxValue(int n, int index, int S) {

        int l = 1, r = S - n + 1, ans = 1;

        while(l <= r)
        {
            int x = (l + r) / 2;

            long long sum1 = get_sum(index, x);
            long long sum2 = get_sum(n - index - 1, x);

            if(sum1 + sum2 + x <= S)
            {
                ans = max(ans, x);
                l = x + 1;
            }
            else 
                r = x - 1;
        }

        return ans;
    }
};