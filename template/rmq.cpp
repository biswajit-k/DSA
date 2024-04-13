/**
 * Description: Performs range MINIMUM queries on a static array.
 * Source: Competitive Programming 3
 * Verification: https://www.spoj.com/problems/RMQSQ/
 * Time: O(n log n) build, O(1) query
 */

template<typename T>
struct RMQ {
    vector<vector<T>> spt;

    RMQ(const vector<T> &a) : spt(1, a) {
        int n = (int) a.size();
        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++)
                spt[j][i] = min(spt[j-1][i], spt[j-1][i+(1<<(j-1))]);
        }
    }

    T query(int i, int j) {
        int k = __lg(j - i + 1);
        return min(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

/**
 * Description: Performs range MAXIMUM queries on a static array.
 * Source: Competitive Programming 3
 * Verification: https://www.spoj.com/problems/RMQSQ/
 * Time: O(n log n) build, O(1) query
 */

template<typename T>
struct RMQ2 {
    vector<vector<T>> spt;

    RMQ2(const vector<T> &a) : spt(1, a) {
        int n = (int) a.size();
        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++)
                spt[j][i] = max(spt[j-1][i], spt[j-1][i+(1<<(j-1))]);
        }
    }

    T query(int i, int j) {
        int k = __lg(j - i + 1);
        return max(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

class Solution {
public:
    long long continuousSubarrays(vector<int>& a) {
        RMQ<int> m1(a);
        RMQ2<int> m2(a);
        long long ans =0;
        int n = a.size();
        for (int i=0; i<n;i++) {
            int low = i, hi = n - 1;
            while (low != hi) {
                int m = (low + hi) / 2 + 1;
                if (m2.query(i, m) - m1.query(i, m) <= 2)
                    low = m;
                else
                    hi = m - 1;
            }
            ans += low - i + 1;
        }
        return ans;
    }
};

/* 
usage-
    vector<int> v = {1, 5, -1, 30, 6, 7, 4, 5, 8};
    RMQ2 mx(v);
    RMQ mi(v);

    cout << mi.query(3, 5);     // for minimum element in [3, 5] idx

 */