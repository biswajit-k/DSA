#include<bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
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
#define nax                 (llint)(1e5 + 5)

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



llint solve(llint l, llint r) {

    // dp[i][j][k] -> numbers starting from pos 'i', with left flex 'j' and right flex 'k'
    llint dp[25][2][2];                 
    memset(dp, -1, sizeof(dp));
    vector<int> bl, br;             // digits seperated

    while(l) {
        bl.push_back(l % 10);
        l /= 10;
    }
    while(r) {
        br.push_back(r % 10);
        r /= 10;
    }
    int diff = sz(br) - sz(bl);
    for(int i = 0; i < diff; i++)    bl.push_back(0);
    reverse(all(bl));
    reverse(all(br));
    deb(sz(bl));
    function<llint(int, int, int)> call = [&](int pos, int fl, int fr) {

        if(pos == sz(bl))   return 1ll;

        llint &x = dp[pos][fl][fr];

        if(x != -1) return x;
        
        int liml = 0, limr = 9;
        if(fl == 0) liml = bl[pos];
        if(fr == 0) limr = br[pos];

        llint ans = 0;
        for(int i = liml; i <= limr; i++)
        {
            int npos = pos + 1, nfl = fl, nfr = fr;

            if(fl == 0 && i > liml) nfl = 1;
            if(fr == 0 && i < limr) nfr = 1;

            ans += call(npos, nfl, nfr);
        }
        return x = ans;
    };

    return call(0, 0, 0);
}

void solve() {  

    llint a, b;
    cin >> a >> b;

    cout << b - a + 1ll << '\n';

}

int main()
{   
    boost;
    int t = 1 ;
    // cin >> t;
    for(int i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}

