class Solution {
public:

    int nthUglyNumber(int n) {
        
        if(n == 1)
            return 1;
        
        vector<int> ugly(n, 0);
        ugly[0] = 1;

        int ptr_2, ptr_3, ptr_5, next_idx = 1;
        ptr_2 = ptr_3 = ptr_5 = 0;

        auto get_value = [&](int base, int idx) {
            return base * ugly[idx];
        };

        for(int i = 0; i < n - 1; i++)
        {
            int mi = min({get_value(2, ptr_2), get_value(3, ptr_3), get_value(5, ptr_5)});

            if(get_value(2, ptr_2) == mi)
                ptr_2++;
            if(get_value(3, ptr_3) == mi)
                ptr_3++;
            if(get_value(5, ptr_5) == mi)
                ptr_5++;

            ugly[next_idx++] = mi;
        }

        return ugly[n - 1];
    }
};