#include<bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
#define llint long long int
#define all(v) v.begin(),v.end()
#define sz(x) (int)(x).size()
#define deb(x) cerr<<#x<<" is "<<x<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define mod int(1e9 + 7)
#define nax int(2e6	 + 5)

llint ceil_div(llint a, llint b) {return a % b == 0 ? a / b : a / b + 1;}
void google(int t) {cout << "Case #" << t << ": ";}

//*************************** Template Ends *******************************//

const int bit_size = 100;

int bit[bit_size + 1];

llint prefix_sum(int i) {
    llint sum = 0;
    for(; i > 0; i -= (i & -i))
        sum += bit[i];
    return sum;
}

void add_value(int i, llint value) {
    for(; i <= bit_size; i += (i & -i))
        bit[i] += value;
}

llint range_sum(int i, int j) {
    return prefix_sum(j) - prefix_sum(i - 1);
}

void init() {
    for(int i = 1; i <= bit_size; i++)
    {
        int child = i + (i & -i);
        if(child <= bit_size)
            bit[child] += bit[i];
    }
}

void set_value(int i, llint value) {
    add_value(i, value - range_sum(i, i));
}

void solve()
{
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
