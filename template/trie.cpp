#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define sz(x) (int)(x).size()
#define deb(x) cerr<<#x<<" is "<<x<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define mod int(1e9 + 7)
#define nax int(1e5	 + 5)

llint ceil_div(llint a, llint b) {return a % b == 0 ? a / b : a / b + 1;}
void google(int t) {cout << "Case #" << t << ": ";}

//*************************** Template Ends *******************************//

const int alpha_size = 26;

struct Trie {
	bool present;
	Trie* child[alpha_size];
	// unordered_map<char, Trie*> child;	// or use map instead of child array (save space)
};

Trie* getNode()
{
	Trie* node = new Trie();
	node -> present = false;
	for(int i = 0; i < alpha_size; i++)
		node -> child[i] = nullptr;
	return node;
}

void insert(Trie* root, string s)
{
	Trie* curr = root;
	for(auto c: s)
	{
		int idx = c - 'a';
		if(!curr->child[idx])
			curr -> child[idx] = getNode();
		curr = curr -> child[idx];
	}
	curr -> present = true;
}

Trie* search(Trie* root, string s)
{
	Trie* curr = root;
	for(auto c: s)
	{
		int idx = c - 'a';
		if(!curr->child[idx])
			return nullptr;
		curr = curr->child[idx];
	}
	return (curr -> present ? curr : nullptr);
}




void solve() {



}

int main() {	
	boost
	int t = 1;
	// cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}

