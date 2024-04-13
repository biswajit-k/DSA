#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//        int,string        greater<int>, less_equal<int> i.e repeated values allowed ,less<int>
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key


int main() {
	
	ordered_set os;
	os.insert(9);
	os.insert(1);
	os.insert(5);
	
	auto x = os.order_of_key(6);
	cout << x;

}