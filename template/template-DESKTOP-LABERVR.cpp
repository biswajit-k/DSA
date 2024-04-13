#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define Fill(a,b)  memset(a,b,sizeof(a))
#define what_is(x) cerr<<#x<<"is"<<x<<'\n';
#define google cout<<"Case #"<<ll<<": "<<day<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define mod int(1e9+7)

llint ans[100006];
void solve(){
    ans[0]=1;
    ans[1]=1;
    for(int i=2;i<100005;i++)
    {
        ans[i]=(ans[i-1]%mod+ans[i-2]%mod)%mod;
    }

}
int main(){
    boost
    cout<<"hello";
    return 0;
}