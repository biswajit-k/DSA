class Solution {
public:

    const int mod = 1e9 + 7;

    int knightDialer(int n) {

        vector<long long> count(10, 1), temp(10);
        vector<vector<int>> reach(10);
        reach[0] = {4, 6};
        reach[1] = {6, 8};
        reach[2] = {7, 9};
        reach[3] = {4, 8};
        reach[4] = {3, 9, 0};
        reach[6] = {1, 7, 0};
        reach[7] = {2, 6};
        reach[8] = {1, 3};
        reach[9] = {4, 2};

        for(int i = 0; i < n - 1; i++)
        {
            temp = count;
            for(int i = 0; i < 10; i++)
            {
                count[i] = 0;
                for(auto& x: reach[i])
                    count[i] = (count[i] + temp[x]) % mod;
            }
        }

        long long ans = 0;
        for(int i = 0; i < 10; i++)
            ans = (ans + count[i]) % mod;
        
        return ans;
    }
};