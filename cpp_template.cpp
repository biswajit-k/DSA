#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define Fill(a,b)  memset(a,b,sizeof(a))
#define deb(x) cerr<<#x<<"is"<<x<<'\n';
#define google cout<<"Case #"<<ll<<": "<<day<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define mod int(1e9+7)


/////////////////////// random number
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
llint getRandomNumber(llint l, llint r) {return uniform_int_distribution<llint>(l, r)(rng);} 

//////////////////////////// Ceil division

llint ceil_div(llint a, llint b) {return a % b == 0 ? a / b : a / b + 1;}

//////////////////////////// Modulo exponentiation

llint modExponent (llint x, llint n, llint m){
    if (n == 0)
        return 1;
    if(n % 2 == 1)
        return ((x * (modExponent(x, n-1, m)) % m) % m);
    
    llint temp = modExponent(x, n/2, m) % m;
    return ( temp * temp) % m;
}

// extended eucledian - gcd (a, b) = a * x + b * y, for integers +,- or 0 x and y
// modulo inverse of a, and m existi iff a, m are coprime
// compute (a / b)  % m == a%m * b-1 %m +> find bx + my = 1

llint X, Y;
llint extendedEuclid(llint A, llint B) {
    if(B == 0) {
        X = 1;
        Y = 0;
        return A;
    }
    else {
        llint gcd = extendedEuclid(B, A%B);
        llint temp = X;
        X = Y;
        Y = temp - (A/B)*Y;
        return gcd;
    }
}
llint moduloInverse(llint b, llint m) { 

    extendedEuclid(b, m);
    return (X%m + m) % m;           // x maybe -ve

    // when m is prime use, b^(m-2) % m as modulo inverse
}
// Modulo Inverse from (1 to n) under mod m - O(N)
void modInverseRange(int n, llint m) 
{
    llint inv[n + 1];
    inv[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        inv[i] = (-(m / i) * inv[m % i]) % m;
        inv[i] = inv[i] + m;
    }
}



////////////////////////////////////////// seieve
void seieve(){

    const int N = 4e4;
    bool isprime[N + 1];
    vector<llint> primes;
    for(int i = 0; i <= N; i++)
        isprime[i] = 1;
    
    for(int i = 2; i <= N; i++)
        if(isprime[i])
            for(int j = i; j <= N; j += i)     // primes less than will be covered before
                isprime[j] = 0;

    for(int i = 2 ; i <= N; i++)
        if(isprime[i])
            primes.push_back(i);

}

/////////////////////////// binary search for vector
int bsearch(vector<int>& a, int x){
	int l = 0, r = int(a.size()) - 1;
	while(l < r){
		int mid = l + (r - l) / 2;
		if(a[mid] == x) return mid;	
		if(a[mid] < x) l = mid + 1;		
		else r = mid - 1;
	}return (a[l] == x ? l : -1);
}

///////////////////////////////////////////////////// fraction class       
class Fraction {
    public:
    llint num, den;
    Fraction(int n = 0, int d = 1)
    {
        num = n;
        den = d;   
    }
    void addfraction(const Fraction& F) {
    
        llint lcm = (1ll * den * F.den)/__gcd(den, F.den);
        llint finalden = lcm;
        llint finalnum = num * (lcm/den) + F.num * (lcm/F.den);
        num = finalnum;
        den = finalden;
    
    }

    void mulfraction(const Fraction& F) {
        llint n = F.num * num;
        llint d = F.den * den;
        llint gc = __gcd(n, d);
        n = n/gc; d = d/gc;
        num = n; den = d;

    }
    
};


////////////////////////////////////////// 2d prefix sum 
// sum2d() stores values
// getcost() give sum of values b/w p1, p2


void sum2d(vector<vector<int>>& grid, vector<vector<int>>& prefsum){

    int n = prefsum.size();
    int m = prefsum[0].size();     //  n x m prefsum

    // indexing from 1 to n , make sum 0 for 0th row and column

    for(int i = 0; i < n; i++)
    {
        prefsum[i][0] = 0;
    }
    for(int i = 0; i < m; i++)
    {
        prefsum[0][i] = 0;
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)  
        {
            prefsum[i][j] = prefsum[i][j-1] + prefsum[i-1][j] - prefsum[i-1][j-1] + grid[i][j];
        }
    }

}


int getcost(vector<vector<int>>& prefsum, pair<int, int> p1, pair<int, int> p2){

    int cost = 0;
    cost += prefsum[p2.first][p2.second] - prefsum[p1.first - 1][p2.second] - prefsum[p2.first][p1.second - 1] + prefsum[p1.first - 1][p1.second - 1];
    return cost;

}


////////////////////////////////// run_length_encoding
// find count of each repeating elements in iterable

// EXAMPLE 1
// string s = "aab**c**aabb*d";
// 	auto encoding = run_length_encoding<char>(s);

// EXAMPLE 2
// vector<int> a = {1, 1, 3, 4, 4, 5, 5, 3, 2};
// auto encoding = run_length_encoding<int>(a);

// 	for(auto pr: encoding)
// 		cout << pr.first << ' ' << pr.second << '\n';

template<typename T, typename T_iterable>
vector<pair<T, int>> run_length_encoding(const T_iterable &items) {
    vector<pair<T, int>> encoding;
    T previous;
    int count = 0;
 
    for (const T &item : items)
        if (item == previous) {
            count++;
        } else {
            if (count > 0)
                encoding.emplace_back(previous, count);
 
            previous = item;
            count = 1;
        }
 
    if (count > 0)
        encoding.emplace_back(previous, count);
 
    return encoding;
}

/////////////////////////////////////////////////
// set comparator 

auto cmp = [](pair<int, int> a, pair<int, int> b){

        // remember -> comparator should return either a > b or b > a else it will 
        // assume both element same and only insert 1 value
		if(a.second != b.second)            // if a.se = b.se do another comparison
			return a.second > b.second;
		return a.first > b.first;           // a.fi, b.fi always differ
};
set<pair<int, int>, decltype(cmp)> st(cmp);

///////////////////////////////////////////////////
// priority_queue comparator
auto comp = [](int a, int b) {
    return a > b;                   // a, b order true => a will pop at LAST AFTER b
};
priority_queue<int, vector<int>, decltype(comp)> pq(comp);

// return no. of divisors - O(Sqrt(N))
int divisorCount(int n) {
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
        if (n % i == 0)
        {
            if (n / i == i) cnt++;
            else    cnt = cnt + 2;
        }
    return cnt;
}

// interactive
int ask(int a, int b) {
  cout << "? " << a << " " << b << endl;
  cout.flush();
  int ans;
  cin >> ans;
  return ans;
}

//////////////////////////////////////// 
// lambda function
function<int(int, int)> dfs_lambda = [&](int i,int par){
    return 1;
};

///////////////////////////////////////
// DSU class
// usage: DSU dsu(n); dsu.join(a, b); dsu.find(a);
//
class DSU {
    vector<int> Parent, Rank;
    public:
    DSU(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);
        for (int i = 0; i < n; i++) Parent[i] = i;
    }
    int find(int x) {
        return Parent[x] = Parent[x] == x ? x : find(Parent[x]);
    }
    bool join(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset != yset) {
            Rank[xset] < Rank[yset] ? Parent[xset] = yset : Parent[yset] = xset;
            Rank[xset] += Rank[xset] == Rank[yset];
            return true;
        }
        return false;
    }
};







/*
    TIPS-
        -- even fibonacci F(nth) = 4* F(n-1) + F(n-2)
        -- when m is prime use, b^(m-2) % m as modulo inverse

*/







int main(){
    boost

    return 0;
}
