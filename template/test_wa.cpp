#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define all(v)              v.begin(),v.end()
#define sz(x)               (int)(x).size()
#define set_bits            __popcount
#define boost               std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define deb(x) cerr<<#x<<" is "<<x<<'\n';
typedef long long int       llint;
typedef pair<llint,llint>   pll;
typedef pair<int, int>      pii;
typedef long double         ld;
#define mod                 (llint)(1e9 + 7)

llint ceil_div(llint a, llint b) {return a % b == 0 ? a / b : a / b + 1;}
llint mod_expo(llint a, llint b, llint m) {llint res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
void extended_gcd(llint a, llint b, llint*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extended_gcd(b, a % b, v); llint x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //size- 3
llint mod_inv(llint a, llint b) {llint arr[3]; extended_gcd(a, b, arr); return arr[0];} //for non prime b
llint mod_inv_prime(llint a, llint b) {return mod_expo(a, b - 2, b);}
void fact_range(llint n, llint m, llint* fact) { fact[0] = 1; for(llint i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % m; }
void mod_inv_range(llint n, llint m, llint* inv) {  inv[1] = 1;for(int i = 2; i <= n; i++) { inv[i] = (-(m / i) * inv[m % i]) % m; inv[i] = inv[i] + m; } } // size- n + 1
void fact_inv_range(llint n, llint m, llint* inv, llint* factinv) { factinv[0] = factinv[1] = 1; for(llint i = 2; i <= n; i++) factinv[i] = (factinv[i - 1] * inv[i]) % m; }
llint combination(llint n, llint r, llint m, llint *fact, llint *factinv) {llint val1 = fact[n]; llint val2 = factinv[n - r]; llint val3 = factinv[r]; return (((val1 * val2) % m) * val3) % m;}
llint phi_n(llint n) {llint num = n; if (n % 2 == 0) {num /= 2; while (n % 2 == 0) n /= 2;} for (llint i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; num = (num / i * (i - 1));}} if (n > 1)num = (num / n * (n - 1)) ; return num;} //O(sqrt(N))
void google(int t) {cout << "Case #" << t << ": ";}
void initncr() { const int NN = 100004, MM = 1000000007; llint fact[NN + 1], inv[NN + 1], factinv[NN + 1]; fact_range(NN, MM, fact); mod_inv_range(NN, MM, inv); fact_inv_range(NN, MM, inv, factinv); }

//*************************** Template Ends *******************************//


void solve() {  

}

int main()
{   
    boost;
    int t ;
    cin >> t;

    // T: no of test cases, I: on which WA
    int T, I;
    if(t == T)
    {
        for(int i = 1; i <= t; i++)
        {
            // input here -------------
            int n; 
            cin >> n;
            vector<int> a(n);
            for(auto& x: a)
                cin >> x;
            // ------------------------

            if(i == I)
            {
                cout << n << '\n';
                for(int i = 0; i < n; i++)
                    cout << a[i] << " \n"[i ==  n - 1];
            }

        }
    }
    else
    for(int i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}

/* 
1. what things imply on reaching still.
2. think sometime about implementation - new idea shoud meet requirements
3. better debugging... - got stuck - where, do deb(), run cases, missed all requirement
4. better version of check()
5. make simple observations from others code - how they satisfy requirement
6. confirm on the conditions before coding it - else waste time
7. check for min, max size of input
 */

