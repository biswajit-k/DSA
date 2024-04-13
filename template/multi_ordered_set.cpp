#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define sz(x) (int)(x).size()
#define deb(x) cerr<<#x<<" is "<<x<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define mod int(1e9 + 7)
#define nax int(2e5	 + 5)

using namespace std;
namespace __gnu_pbds{
          typedef tree<int,
                       null_type,
                       less_equal<int>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;
 
 

llint ceil_div(llint a, llint b) {return a % b == 0 ? a / b : a / b + 1;}
void google(int t) {cout << "Case #" << t << ": ";}

//*************************** Template Ends *******************************//

bool Exist(ordered_set &s,int x){ //this function checks weather the value (x) exists in the set or not.
 
     if((s.upper_bound(x))==s.end()){
        return 0;
     }
     return ((*s.upper_bound(x))==x);
 
}
 
int FirstIdx(ordered_set &s,int x){ //this function returns the first index of the value (x)..(0 indexing).
 
    if(!Exist(s,x)){
        return -1;
    }
    return (s.order_of_key(x));
 
}
 
 
int Value(ordered_set &s,int idx){ //this function returns the value at the index (idx)..(0 indexing).
 
   return (*s.find_by_order(idx));
 
}
 
 
int LastIdx(ordered_set &s,int x){ //this function returns the last index of the value (x)..(0 indexing).
 
    if(!Exist(s,x)){
        return -1;
    }
    if(Value(s,(int)s.size()-1)==x){
        return (int)(s.size())-1;
    }
    return FirstIdx(s,*s.lower_bound(x))-1;
 
}
 
 
int Count(ordered_set &s,int x){ //this function returns the number of occurrences of the value (x).
 
     if(!Exist(s,x)){
        return 0;
     }
     return LastIdx(s,x)-FirstIdx(s,x)+1;
 
}

// numbers smaller than x
int Small(ordered_set &s,int x){

	if(s.end() == s.lower_bound(x))
		return (sz(s) - Count(s, x));
	
	return (FirstIdx(s, *s.lower_bound(x)) - Count(s, x));

}
// numbers bigger than x
int Big(ordered_set &s,int x){
	return (sz(s) - Small(s, x) - Count(s, x));
}

int main() {	
	boost
	int t;
	cin >> t;
	
	while(t--)
	{
		// solve();
	}
	

	return 0;
}

