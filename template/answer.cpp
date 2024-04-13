#include<bits/stdc++.h>
#define llint long long int
#define all(v) v.begin(),v.end()
#define Fill(a,b)  memset(a,b,sizeof(a))
#define what_is(x) cerr<<#x<<"is"<<x<<'\n';
#define google cout<<"Case #"<<ll<<": "<<day<<'\n';
#define boost std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod int(1e9+7)
using namespace std;

void solve()
{
    int n,maxel=-111;
    cin>>n;
    vector<int> a(n);
    bool ifz=false,negthere=false;
    int hcf = -1;
    for(auto& x:a)
    {
        cin>>x;
        maxel = max(maxel, x);

        if (hcf == -1 && x != 0)
            hcf = x;
            
        if(x == 0)
            ifz=1;
        else if(x<0)
        {
            negthere=true;
            break;
        }
        else
            hcf = __gcd(hcf,x);

    }
 
    if(negthere)
    {
        cout<<"no\n";
        return;
    }
    if(maxel != 0)
    {
        if(maxel/hcf>300)
        {
            cout<<"NO\n";
            return;
        }

        int k = ifz?0:hcf;
        cout<<"yes\n";
        cout<<(ifz?maxel/hcf+1:maxel/hcf)<<'\n';
        
        for(;k<=maxel;k+=hcf)
            cout<<k<<' ';
        cout<<'\n';
    }
    else 
        cout<<"yes\n"<<0<<'\n';
}

int main(){
    boost
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        
      
    }   
    return 0;
}